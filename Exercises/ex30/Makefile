CFLAGS = -g -O2 -Wall -Wexstra -Isrc -rdynamic -DNDEBUG $(OPTFLAGS) # optflags lets people adjust build options as needed
LIBS = -ldl $(OPTLIBS) # options used when linking a library, can augment.
PREFIX ?= /usr/local # will only have this value if no makefile setting

SOURCES = $(wildcard src/**/*.c src /*.c) # dynamically creates the sources variable by doing a wildcard search for all c files in the src directory
OBJECTS = $(patsubst %.c, *.o, $(SOURCES)) # takes sources list and makes new list of all object files

TEST_SRC = $(wildcard tests/*_tests.c) # finds all test source files for unit tests
TESTS = $(patsubst %.c, %, $(TEST_SRC)) # takes test source list and gets all test targets

TARGET = build/libYOUR_LIBRARY.a # target of all this
SO_TARGET = $(patsubst %.a, %.so, $(TARGET))
# The Target build
all: $(TARGET) $(SO_TARGET) tests # signifies which library to build

dev: CFLAGS = -g -Wall -Isrc -Wall -Wexstra $(OPTFLAGS) # for making dev builds, intoduces technique for changing options for just one target
dev: all

$(TARGET): CFLAGS += -fPIC # Builds the target library
$(TARGET): build $(OBJECTS) # make the build directory, and compile the objects
		ar rcs $@ $(OBJECTS) # ar command actually makes the target. "Put the target for the makefile source here and all the objects after that"
		ranlib $@ # generates index to contents

$(SO_TARGET): $(TARGET) $(OBJECTS) # makes build or bin directories if they don't exist
		$(CC) -shared -o $@ $(OBJECTS)

build:
		@mkdir -p build
		@mkdir -p bin

# The Unit Tests
.PHONY: tests # tags directories or files with same name as target, so they can be ignored
tests: CFLAGS += $(TARGET) # adds target to build so that each test program will be linked with target library
tests: $(TESTS) # builds each program in TESTS
		sh ./tests/runtest.sh

valgrind: # runs under valgrind, puts valgrind logs in a file
		VALGRIND="valgrind --log-file=/tmp/valgrind-%p.log" $(MAKE)

# The Cleaner
clean: # Cleans out most of the junk that various compilers and tools leave behind
		rm -rf build $(OBJECTS) $(TESTS)
		rm -f tests/tests.log
		find . -name "*.gc*" -exec rm {} \;
		rm -rf `find . -name "*.dSYM" -print`

# The Install
install: all # runs of all so that 'make install' will build everything
		install -d $(DESTDIR)/$(PREFIX)/lib/ # creates taregt lib directory if it doesn't exist
		install $(TARGET) $(DESTDIR)/$(PREFIX)/lib/ # actually installs library

# The Checker
BADFUNCS = '[^_.>a-zA-Z0-9](str(n?cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)|stpn?cpy|a?sn?printf|byte_)' # idenifier of bad functions
check:
		@echo Files with potentially dangerous functions. # prints the following
		@egrep $(BADFUNCS) $(SOURCES) || true # Scans for bad functions

#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int (*lib_function)(const char *data); // this function pointer definition is used to call functions in the library

int main(int argc, char *argv[])
{
    int rc = 0;
    check(argc == 4, "USAGE: ex29 libex29.so function data");

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];

    void *lib = dlopen(lib_file, RTLD_NOW); // dlopen loads library
    check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror()); // dlerror is used to find out what lib-related error is

    lib_function func = dlsym(lib, func_to_run); // dlsym gets funciton out of the lib (func_to_run)
    check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror())

    rc = func(data); // calls function from lib
    check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

    rc = dlclose(lib); // closes lib just like a file
    check(rc == 0, "Failed to close %s", lib_file);

    return 0;

error:
    return 1;
}

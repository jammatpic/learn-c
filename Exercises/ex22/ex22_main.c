#include "ex22.h"
#include "dbg.h"

// NONE OF THIS ACTUALLY WORKS DUE TO LINKING ERROR, BUT I UNDERSTAND SCOPE ANYWAY

// notes:
// Pass by reference: passing the actual thing being referenced
// Pass by value: passing a local copy of the thing being referenced

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
    log_info("Count is: %d", count);

    if(count > 10) {
        int count = 100; // not good!

        log_info("count in this scope is %d", count);
    }

    log_info("count is at exit: %d", count);

    count = 3000;

    log_info("count after assign: %d", count);
}

int main(int argc, char *argv[])
{
    // test out THE_AGE accessors
    log_info("My name: %s, age %d", MY_NAME, get_age());

    set_age(100);

    log_info("My age is now: %d", get_age());

    // test out THE_SIZE extern
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();

    // test the ratio function static
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(300.0));

    //test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count*20);

    log_info("count after calling scope_demp: %d", count);

    return 0;
}

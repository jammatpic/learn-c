#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("---AVAILABLE DATA TYPES---\n");

    int a = 15;
    double b = 123.1;
    float c = 123.1;
    char d = 'd';

    printf("This is an int (16-bits, signed): %d\n", a);
    printf("This is a double-precision float (32 bits, signed): %f\n", b);
    printf("This is a single-precision float (16 bits, signed): %f\n", c);
    printf("This is a character: %c\n\n", d);

    printf("---TYPE MODIFIERS---\n");
    printf("---These modifiers can apply to any of the above data types, and can also be combined with one another---\n");

    unsigned int e = 10;
    signed int f = -10;
    long double g = 123456;
    short int h = 8;

    printf("This is an unsigned int, meaning it has a upper bound twice the size, but nothing lower than 0: %u\n", e);
    printf("This is a signed int, meaning it has a normal bound that inlcudes negative numbers (c does not have unsinged floats): %d\n", f);
    printf("This is a long double, meaning it has double precision, and takes twice the space: %Lf\n", g);
    printf("This is a short int, meaning it has a upper bound half the size, but halves the space: %hi\n\n", h);

    printf("---TYPE QUALIFIERS---\n");
    printf("---These modifiers can apply to any of the above data types, and can also be combined with one another---\n");

    printf("---A REMINDER---\n");
    printf("If you're trying to find out how type conversions are working in an exporession, use explicit casts.\n");
    printf("The compiler will promote the smaller side to match the larger side before doing an operation.\n");
    printf("Always promote up, not down.\n\n");

    printf("---OPERATORS---\n");
    printf("++x: Increment, then read\n");
    printf("x++: Read, then increment\n");
    printf("->: Struct pointer access\n");
    printf(".: Struct value access\n");
    printf("&: address of (if unary)\n");
    printf("*: value of\n\n");

    printf("---BIT/BOOLEAN OPERATORS---\n");
    printf("&: Bitwise and (if binary)\n");
    printf("<</>>: Shift left/right\n");
    printf("^: Bitwise XOR\n");
    printf("|: Bitwise OR\n");
    printf("~: Compliment\n");
    printf("Ternary truth test: X ? Y : Z 'if X then Y else Z'\n\n");

    printf("---OTHER CONTROL STRUCTURES---\n");
    printf("do-while: do {...} while(X); Executes code in block, then tests expression.\n");
    printf("continue: Stops the body of a loop, and jumps to the test, so it can continue\n");
    printf("goto: Jumps to a spot in code with a ':label'\n");


    return 0;
}

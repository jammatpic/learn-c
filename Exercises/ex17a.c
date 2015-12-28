#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int limit = 5;
int len = 0;

void array_print(int a[])
{
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("%d\n", a[i]);
    }
}

void push(int a[], int num)
{
    if (len < limit) {
        a[len] = num;
        len++;
        array_print(a);
    } else {
        printf("stack is full!\n");
    }
}

void pop(int a[])
{
    if (len > 0) {
        a[len] = '\0';
        len--;
        array_print(a);
    } else {
        printf("stack is empty!\n");
    }
}

int main(int argc, char *argv[])
{
    int the_array[limit];

    for (;;) {
        char command[32];
        int input_num = -1;

        printf("Enter your command: ");
        fgets(command, 32, stdin);
        command[strlen(command)-1] = '\0';

        if (strcmp(command, "stop") == 0) {
            return 0;
        } else if (strcmp(command, "push") == 0){
            printf("Enter an integer to push: ");
            fgets(command, 32, stdin);
            input_num = atoi(command);
            push(the_array, input_num);
        } else if (strcmp(command, "pop") == 0){
            pop(the_array);
        } else {
            printf("you must enter 'push', 'pop', or 'stop'\n");
        }
    }
}

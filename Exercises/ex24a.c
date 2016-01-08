#include <stdio.h>
#include "dbg.h"

void strip_whitespace(char str[])
{
    char new_str[strlen(str)];
    int j = 0;
    int i = 0;
    for (i = 0; i < strlen(str); i++) {
        if (isspace(str[i]) == 0 && str[i] != '\n') {
            new_str[j] = str[i];
            j++;
        }
    }
    printf("%s", str);
    printf("%s\n", new_str);
}

int main(int argc, char *argv[])
{
    strip_whitespace("The quick brown fox jumped over the lazy dog.");
}

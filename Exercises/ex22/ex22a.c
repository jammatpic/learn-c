#include <stdio.h>

void overflo(int num)
{
    printf("%d\n",num);
    num += 2;
    overflo(num);
}

int main(int argc, char *argv[])
{
    printf("This is a thing");
    overflo(2);
    return 0;
}

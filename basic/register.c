#include <stdio.h>

int main(void)
{
    register int x = 1;
    int y = 2;
    printf("%d", x + y);
    return 0;
}
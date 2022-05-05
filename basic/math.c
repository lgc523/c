#include <stdio.h>
#include <math.h>
#include <tgmath.h>

int main(void)
{
    long double num = -10.1;
    printf("%.1Lf\n", fabsl(num));
    //fabsl l 表示 long
    //fabs 宏函数，宏在展开时，会自动匹配对应的类型精确版本，需要倒入tgmath.h
    printf("%.1Lf\n", fabs(num));
}
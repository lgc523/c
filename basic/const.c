#include <stdio.h>

int main(void)
{
    const int vx = 10;
    const int vy = 10;
    // const 修饰的只读变量不具有常量表达式的属性，无法用来定义数组大小、用在case语句中
    //常量表达式本身会在程序编译时呗求值，只读变量的值只能够在程序实际运行时才被得知
    //编译器通常不会对只读变量进行内联处理

    int arr[vx] = {1, 2, 3};
    switch (vy)
    {
    case vx:
        puts("value mtched!");
        break;
    default:
        break;
    }
}

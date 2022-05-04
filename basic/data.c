#include <stdio.h>

//
// Created by spider on 2021/3/24.
//
void division() {
    printf("%d", 5 / 1);
    printf("%f", 5.0 / 1);
// 取余只能使用整数,符号取决于被模数
    printf("%d", -15 / 5);
    printf("%d", 15 / -5);
    printf("%c", 25 > 24 ? 'y' : 'n');
    printf("\n");
}

void printNNE() {
    for (int i = 1; i < 10; ++i) {
        for (int j = 1; j < i + 1; ++j) {
            printf("%d * %d = %d ", i, j, i * j);
        }
        printf("\n");
    }
}
//变量存储类别,根据变量的生存周期划分，可以分为静态存储方式和动态存储方式
//1.静态存储方式:程序运行期间分配固定的存储空间的方式，静态存储区中存放了在整个程序执行过程中都存在的变量
//2.动态存储方式,程序运行期间根据需要记性动态的分配存储空间，动态存储区中存放的变量是根据程序运行的需要而建立和释放的
//  通常包括:函数形式参数，自动变量，函数调用时的现场保护和返回地址

//自动、静态、寄存器的、外部的

int func() {
    auto int i = 10;//auto 可省略,自动存储类别，属于动态存储类别
    printf("动态自动存储 i=%d\n", i);
    static char s[1] = {'a'}; //静态局部变量属于静态存储类别,在静态存储区内分配存储单元，在程序整个运行期间都不释放
    //静态局部变量在编译时赋初值，即只赋初值一次，默认编译赋零值
    register long l = 120;//为了提高效率，允许将局部变量的值放在寄存器中
    //只有局部自动变量和形式参数可以作为寄存器变量,局部静态变量不能定义为寄存器变量
    extern int st;//外部变量，函数可以调用在该函数之后定义的变量
    printf("extern st =%d \n", st);
    return st;
}

int st = 5;

int arr() {
    enum E {
        one = 1,
        two,
        three,
        four,
        five

    } element;

    // 遍历枚举元素
    for (element = 1; element <= 3; element++) {
        printf("枚举元素：%d \n", element);
    }
    enum E e;
    int six = 5;
    e = (enum E) six;
    int arr[] = {1, 2, 3, e};
    //c 不提供数据长度计算

    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("arr index of %d is %d", i, arr[i]);
    }
    return e;
}


#include <strings.h>
#include <stdio.h>

int main(void)
{
    //字符串形式 数组、指针
    const char strA[] = "Hello,geek";
    // C 标准中规定，连续出现的字符串字面量之阿金如果仅由空格分割，则会将他们视为一个整体
    const char *strB = "hello"
                       ",geek";
    // strA == strB
    printf("%p\n%p\n", strA, strB);
    printf("%s\n%s\n", strA, strB);

    // strlen 统计长度,不会计入多余的终止符
    printf("string len: %zu\n", strlen(strA));

    //不同定义方式在不同情况下可能会产品不同的影响
    //字符串常量一般存放在进程  VAS 的 .rodata Section 中
    //此处的数据一般可以在程序中被多次饮用
    //当数据需要被修改，或以较短生命周期的形式存在时，引用的相关数据可能需要从 .rodata 中被复制到其他地方
    //数组形式定义的字符串，就是将该字符串的数据从 .rodata 中复制到了其他地方
    const char *token = strtok("Hello,geek!", "geek");
    printf("%s", token);
    return 0;
}
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
#define STRLEN 14

int main(void)
{
    printf("char type has %lu byte.\n", sizeof(char));
    // C89 以来的标准中，CHAR_BIT 的值不能小于 8
    printf("char type has %d bits.\n", CHAR_BIT);
    // C90 C11 新增了可用于等宽字符的类型
    // wchar_t wchar16_t wchar32_t wchar_t 类型的大小由具体的编译器实现决定

    //字符串操作
    // 拼接字符串
    char strC[STRLEN] = "Hello,";
    char strD[] = " world!";
    //防止溢出，需要为终止符预留一个字节的空间
    strncat(strC, strD, STRLEN - strlen(strC) - 1);
    printf("strC: %s\n", strC);

    //拷贝字符串
    char strA[] = "aaaaaa";
    char strB[] = "bbbbbbb";
    printf("%s\n", strncpy(strA, strB, strlen(strA)));

    //字符的判断和转换
    char c = 'a';
    printf("%d\n", isalnum(c)); // 1
    printf("%d\n", isalpha(c)); // 1
    printf("%d\n", isblank(c)); // 0
    printf("%d\n", isdigit(c)); // 0
    printf("%d\n", toupper(c)); // A
}
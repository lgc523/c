#include <stdio.h>

int main(void)
{
    printf("Enter some characters:\n");
    FILE *fp = fopen("./temp.txt", "w+");
    // buffer
    char buf[1024];
    //设置缓冲区大小，每输入5字符，就会写入文件，默认4k
    setvbuf(fp, buf, _IOFBF, 5);
    if (fp)
    {
        char ch;
        while (scanf("%c", &ch))
        {
            if (ch == 'z')
                break;
            putc(ch, fp);
        }
    }
    else
    {
        perror("File open failed.");
    }
    fclose(fp);
    return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
    char *p = "hello ";
    char q[20] = "我是梁雲";
    printf("%c\n", *p + 1);
    printf("%s\n", q + 1);
    strcat(q,p);
        printf("%s\n", q);
    return 0;
}
#include<stdio.h>
#include<string.h>
int main()
{
    char s[11];
    scanf("%s", s);
    int i, n = strlen(s);
    for (i = 0; i < n; i++)
        if ('0' <= s[i] && s[i] <= '9')
            printf("%c", s[i]);
    printf("\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
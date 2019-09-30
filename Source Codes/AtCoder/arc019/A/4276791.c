#include<stdio.h>
#include<string.h>
int main()
{
    char s[10];
    scanf("%s", s);
    int i;
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'O')s[i] = '0';
        if (s[i] == 'D')s[i] = '0';
        if (s[i] == 'I')s[i] = '1';
        if (s[i] == 'Z')s[i] = '2';
        if (s[i] == 'S')s[i] = '5';
        if (s[i] == 'B')s[i] = '8';
    }
    printf("%s\n", s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
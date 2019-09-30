#include <stdio.h>
int main()
{
    char s[15];
    scanf("%s", s);
    if (s[5] == '1' || s[6] > '4')
    {
        printf("TBD");
    }
    else
    {
        printf("Heisei");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
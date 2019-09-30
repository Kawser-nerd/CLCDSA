#include<stdio.h>
int main()
{
    char s[111];
    unsigned long long int k;
    scanf("%s", s);
    scanf("%lld", &k);
    unsigned long long int i;
    for (i = 0; i < k; i++)
    {
        if (s[i] != '1')
        {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    printf("1\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld", &k);
     ^
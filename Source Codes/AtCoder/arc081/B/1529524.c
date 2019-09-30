#include <stdio.h>
#define MOD 1000000007

int main()
{
    int n, i;
    char s1[60], s2[60];
    unsigned long int p = 3;

    scanf("%d", &n);
    scanf("%s", s1);
    scanf("%s", s2);
    if (s1[0] != s2[0])
        p *= 2;
    for (i = 0; i < n - 1; i++)
    {
        if (s1[i] == s2[i])
        {
            p = (p * 2) % MOD;
        }
        else
        {
            if (s1[i + 1] != s2[i + 1] && s1[i] != s1[i + 1])
            {
                p = (p * 3) % MOD;
            }
        }
        //printf("%d\n",p);
    }
    printf("%d", p);
    return (0);
} ./Main.c: In function ‘main’:
./Main.c:30:12: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long unsigned int’ [-Wformat=]
     printf("%d", p);
            ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s1);
     ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s2);
     ^
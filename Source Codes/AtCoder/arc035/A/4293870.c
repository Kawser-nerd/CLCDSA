#include<stdio.h>
#include<string.h>
int main()
{
    char s[1003];
    scanf("%s", s);
    int n = strlen(s);
    int i;
    for (i = 0; i < n / 2; i++)
    {
        if (s[i] != '*' && s[n - i - 1] != '*')
        {
            if (s[i] != s[n - i - 1])
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
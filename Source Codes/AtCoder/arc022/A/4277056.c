#include<stdio.h>
#include<string.h>
int main()
{
    char s[102];
    scanf("%s", s);
    int x = 0;
    int n = strlen(s);
    int i = 0;
    while (i < n)
    {
        if (s[i] == 'I' || s[i] == 'i')
        {
            x++;
            break;
        }
        i++;
    }
    while (i < n)
    {
        if (s[i] == 'C' || s[i] == 'c')
        {
            x++;
            break;
        }
        i++;
    }
    while (i < n)
    {
        if (s[i] == 'T' || s[i] == 't')
        {
            x++;
            break;
        }
        i++;
    }
    if (x == 3)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
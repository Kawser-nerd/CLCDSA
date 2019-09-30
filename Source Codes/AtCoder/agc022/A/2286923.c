#include<stdio.h>
#include<string.h>
int main()
{
    char s[30];
    scanf("%s", s);
    int l = strlen(s);
    int i;
    int x = 0;
    if (l == 26)
    {
        for (i = l - 2; i >= 0; i--)
        {
            if (s[i] < s[i + 1])
            {
                x = i + 1;
                break;
            }
        }
        if (x == 0)
        {
            printf("-1\n");
            return 0;
        }
        else
        {
            x--;
            char min = 'z' + 1;
            for (i = x + 1; i < 26; i++)
            {
                if (s[x] - s[i] < 0)
                {
                    if (s[i] < min)
                        min = s[i];
                }
            }
            s[x] = min;
            s[x + 1] = '\0';
            printf("%s\n", s);
            return 0;
        }
    }
    else
    {
        int j;
        for (j = 0; j < 26; j++)
        {
            x = 0;
            for (i = 0; i < l; i++)
            {
                if (s[i] == 'a' + j)
                {
                    x++;
                    break;
                }
            }
            if (x == 0)
            {
                printf("%s%c\n", s, 'a' + j);
                return 0;
            }
        }
    }
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", s);
     ^
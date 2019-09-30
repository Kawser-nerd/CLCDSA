#include<stdio.h>
#include<string.h>
int main()
{
    char s[55], t[55];
    scanf("%s%s", s, t);
    int i, j;
    int n = strlen(s), m = strlen(t);
    if (n < m)
    {
        printf("UNRESTORABLE\n");
        return 0;
    }
    int x;
    for (i = n - m; i >= 0; i--)
    {
        x = 0;
        for (j = 0; j < m; j++)
        {
            if (s[i + j] != '?' && s[i + j] != t[j])
            {
                x++;
                break;
            }
        }
        if (x == 0)
        {
            for (j = 0; j < m; j++)
                s[i + j] = t[j];
            x = -1;
            break;
        }
    }
    if (x != -1)
    {
        printf("UNRESTORABLE\n");
        return 0;
    }
    for (i = 0; i < n; i++)
        if (s[i] == '?')
            s[i] = 'a';
    printf("%s\n", s);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s", s, t);
     ^
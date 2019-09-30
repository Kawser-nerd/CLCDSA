#include<stdio.h>
#include<string.h>
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int main()
{
    int n;
    scanf("%d\n", &n);
    int i;
    char s[102][50];
    for (i = 0; i < n; i++)
        scanf("%s", s[i]);
    int x, j;
    char ss[50];
    for (i = 0; i < n - 1; i++)
    {
        x = 0;
        for (j = 0; j < min(strlen(s[i]), strlen(s[i + 1])); j++)
        {
            if (s[i][strlen(s[i]) - 1 - j] > s[i + 1][strlen(s[i + 1]) - 1 - j])
            {
                x = 1;
                break;
            }
            if (s[i][strlen(s[i]) - 1 - j] < s[i + 1][strlen(s[i + 1]) - 1 - j])
            {
                x = -1;
                break;
            }
        }
        if (x == 0)
        {
            if (strlen(s[i]) < strlen(s[i + 1]))
                x = -1;
            else
                x = 1;
        }
        if (x == 1)
        {
            strcpy(ss, s[i]);
            strcpy(s[i], s[i + 1]);
            strcpy(s[i + 1], ss);
            if (i > 0)
                i -= 2;
        }
    }
    for (i = 0; i < n; i++)
        printf("%s\n", s[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d\n", &n);
     ^
./Main.c:17:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", s[i]);
         ^
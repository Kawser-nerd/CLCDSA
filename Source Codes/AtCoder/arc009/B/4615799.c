#include<stdio.h>
#include<string.h>
int main()
{
    int b[10];
    int i;
    for (i = 0; i < 10; i++)
        scanf("%d", &b[i]);
    int n;
    scanf("%d", &n);
    char a[800][10];
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);
    int c[10];
    for (i = 0; i < 10; i++)
        c[b[i]] = i;
    char aa[10];
    int x, j;
    for (i = 0; i < n - 1; i++)
    {
        x = 0;
        if (strlen(a[i]) > strlen(a[i + 1]))
            x = 1;
        else if (strlen(a[i]) == strlen(a[i + 1]))
        {
            for (j = 0; j < strlen(a[i]); j++)
            {
                if (c[a[i][j] - '0'] > c[a[i + 1][j] - '0'])
                {
                    x = 1;
                    break;
                }
                if (c[a[i][j] - '0'] < c[a[i + 1][j] - '0'])
                    break;
            }
        }
        if (x == 1)
        {
            strcpy(aa, a[i]);
            strcpy(a[i], a[i + 1]);
            strcpy(a[i + 1], aa);
            if (i > 0)
                i -= 2;
        }
    }
    for (i = 0; i < n; i++)
        printf("%s\n", a[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &b[i]);
         ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:13:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", a[i]);
         ^
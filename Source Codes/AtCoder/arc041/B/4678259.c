#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int b[502][502];
    char a[502][502];
    int i, j;
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            b[i][j] = a[i][j] - '0';
    int ans[502][502];
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            ans[i][j] = 0;
    int min;
    for (i = 1; i < n - 1; i++)
    {
        for (j = 1; j < m - 1; j++)
        {
            min = b[i - 1][j];
            if (min > b[i][j - 1])min = b[i][j - 1];
            if (min > b[i + 1][j])min = b[i + 1][j];
            if (min > b[i][j + 1])min = b[i][j + 1];
            ans[i][j] = min;
            b[i][j - 1] -= min;
            b[i][j + 1] -= min;
            b[i - 1][j] -= min;
            b[i + 1][j] -= min;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf("%d", ans[i][j]);
        printf("\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:10:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s", a[i]);
         ^
#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i, j;
    int a[50], b[50];
    for (i = 0; i < m; i++)
        scanf("%d %d", &a[i], &b[i]);
    for (i = 0; i < m; i++)
    {
        a[i]--;
        b[i]--;
    }
    int ans[11] = {};
    int x[11];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 11; j++)
            x[j] = 0;
        x[i] = 1;
        for (j = 0; j < m; j++)
        {
            if (a[j] == i)
                x[b[j]] = 1;
            if (b[j] == i)
                x[a[j]] = 1;
        }
        for (j = 0; j < m; j++)
        {
            if (x[a[j]] == 1)
                if (x[b[j]] != 1)
                    x[b[j]] = 2;
            if (x[b[j]] == 1)
                if (x[a[j]] != 1)
                    x[a[j]] = 2;
        }
        for (j = 0; j < n; j++)
            if (x[j] == 2)
                ans[i]++;
    }
    for (i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &m);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d", &a[i], &b[i]);
         ^
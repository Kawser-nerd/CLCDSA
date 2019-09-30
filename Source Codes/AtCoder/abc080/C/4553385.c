#include<stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int f[102][10];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < 10; j++)
            scanf("%d", &f[i][j]);
    int p[102][11];
    for (i = 0; i < n; i++)
        for (j = 0; j < 11; j++)
            scanf("%d", &p[i][j]);
    int k, m, c;
    k = 1;
    long long int ans = 0, x;
    for (i = 0; i < n; i++)
    {
        m = k;
        c = 0;
        for (j = 0; j < 10; j++)
        {
            if (m % 2 == 1)
            {
                if (f[i][j] == 1)
                    c++;
            }
            m /= 2;
        }
        ans += (long long int)p[i][c];
    }
    for (k = 1; k < 1024; k++)
    {
        x = 0;
        for (i = 0; i < n; i++)
        {
            m = k;
            c = 0;
            for (j = 0; j < 10; j++)
            {
                if (m % 2 == 1)
                {
                    if (f[i][j] == 1)
                        c++;
                }
                m /= 2;
            }
            x += (long long int)p[i][c];
        }
        if (ans < x)
            ans = x;
    }
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &f[i][j]);
             ^
./Main.c:14:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &p[i][j]);
             ^
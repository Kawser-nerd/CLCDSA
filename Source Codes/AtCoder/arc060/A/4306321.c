#include<stdio.h>
int main()
{
    int n, a;
    scanf("%d %d", &n, &a);
    int i, j, k;
    int x[55];
    for (i = 0; i < n; i++)
        scanf("%d", &x[i]);
    unsigned long long int dp[52][52][2505] = {};
    dp[0][0][0] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < 2505; k++)
            {
                if (dp[i][j][k] > 0)
                {
                    dp[i + 1][j][k] += dp[i][j][k];
                    if (k + x[i] < 2505)
                        dp[i + 1][j + 1][k + x[i]] += dp[i][j][k];
                }
            }
        }
    }
    unsigned long long int ans = 0;
    for (i = 1; i <= n; i++)
        ans += dp[n][i][i*a];
    printf("%lld\n", ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &a);
     ^
./Main.c:9:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d", &x[i]);
         ^
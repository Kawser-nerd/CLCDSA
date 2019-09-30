#include<stdio.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int t[6][6];
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < k; j++)
            scanf("%d", &t[i][j]);
    int dp[6][512] = {};
    dp[0][0] = 1;
    int x;
    for (i = 0; i < n; i++)
    {
        for (x = 0; x < 512; x++)
        {
            if (dp[i][x] == 1)
            {
                for (j = 0; j < k; j++)
                    dp[i + 1][x^t[i][j]] = 1;
            }
        }
    }
    if (dp[n][0] == 1)
        printf("Found\n");
    else
        printf("Nothing\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &n, &k);
     ^
./Main.c:10:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d", &t[i][j]);
             ^
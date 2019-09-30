#include <stdio.h>

#define MOD 1000000007LL

int main(void) {
    int i, j, k, l, m, N, dp[110][5][5][5] = {0}, T;
    scanf("%d", &N);

    // 0:A, 1:G, 2:C, 3:T
    // not accepted: 012, 021, 102, 0?12, 01?2 
    // dp[length][n-1 th][n-2 th][n-3th]
    dp[0][3][3][3] = 1;
    for (l=0;l<=N;l++) {
        for (i=0;i<=3;i++) 
        for (j=0;j<=3;j++)
        for (k=0;k<=3;k++) {
            if (!dp[l][i][j][k])  continue;
            for (m=0;m<=3;m++) {
                if      (j==0 && i==1 && m==2) continue;
                else if (j==0 && i==2 && m==1) continue;
                else if (j==1 && i==0 && m==2) continue;
                else if (k==0 && i==1 && m==2) continue;
                else if (k==0 && j==1 && m==2) continue;
                else {
                    dp[l+1][m][i][j] += dp[l][i][j][k];
                    dp[l+1][m][i][j] %= MOD;
                }
            }
        }
    }
    T = 0;
    for (i=0;i<=3;i++) 
    for (j=0;j<=3;j++)
    for (k=0;k<=3;k++) {
        T += dp[N][i][j][k];
        T %= MOD;
    }
    printf("%d\n", T);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
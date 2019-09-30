#include <stdio.h>

#define REP2(i, m, n) for (int i = (m); i < (n); i++)

static int dp[51][51][10001];

int main() {
    int w;
    scanf("%d", &w);
    int n, k;
    scanf("%d%d", &n, &k);
    REP2(i, 1, n + 1) {
        int a, b;
        scanf("%d%d", &a, &b);
        REP2(j, 1, k + 1) {
            REP2(k, 1, w + 1) {
                int m1 = (k - a >= 0) ? dp[i - 1][j - 1][k - a] + b : 0;
                int m2 = dp[i - 1][j][k];
                int m12 = m1 > m2 ? m1 : m2;
                dp[i][j][k] = m12;
            }
        }
    }
    printf("%d\n", dp[n][k][w]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &w);
     ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &n, &k);
     ^
./Main.c:14:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d%d", &a, &b);
         ^
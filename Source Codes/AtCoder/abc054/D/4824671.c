#include <stdio.h>
#define MAX_N 40
#define MAX_A 10
#define MAX_B 10
#define INF 1000000007

int min(int x, int y) {
    return (x < y) ? x : y;
}

int main() {
    int n, ma, mb;
    scanf("%d %d %d", &n, &ma, &mb);

    int dp[MAX_N * MAX_A + 1][MAX_N * MAX_B + 1];
    for (int i = 0; i <= MAX_N * MAX_A; i++) {
        for (int j = 0; j <= MAX_N * MAX_B; j++) {
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for (int k = 0; k < n; k++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        for (int i = MAX_N * MAX_A; i >= a; i--) {
            for (int j = MAX_N * MAX_B; j >= b; j--) {
                dp[i][j] = min(dp[i][j], dp[i - a][j - b] + c);
            }
        }
    }
    int ans = INF;
    for (int ia = ma, ib = mb; ia <= MAX_N * MAX_A && ib <= MAX_N * MAX_B; ia += ma, ib += mb) {
        ans = min(dp[ia][ib], ans);
    }
    printf("%d\n", (ans == INF) ? -1 : ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &n, &ma, &mb);
     ^
./Main.c:24:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d %d %d", &a, &b, &c);
         ^
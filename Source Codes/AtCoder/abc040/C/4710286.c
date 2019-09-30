// https://atcoder.jp/contests/abc040/tasks/abc040_c
#include <stdio.h>
#include <stdlib.h>

#define min(a, b) (a < b ? a : b)

int solv(int n) {
    int i, h[100000];
    int dp[100000];

    for (i = 0; i < n; i++) {
      scanf("%d", h + i);
      dp[i] = 1000000000;
    }
    dp[0] = 0;

    for (i = 0; i < n - 1; i++) {
      dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h [i + 1]));
      if (i + 2 < n) {
        dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h [i + 2]));
      }
    }

    return dp[n - 1];
}

int main(int argc, char **argv) {
  int n;

  while (scanf("%d", &n) != EOF) {
    printf("%d\n", solv(n));
  }

  return 0;
} ./Main.c: In function ‘solv’:
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", h + i);
       ^
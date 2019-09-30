// https://atcoder.jp/contests/abc041/tasks/abc041_d
#include <stdio.h>
#include <stdlib.h>

int n, m, x[121], y[121];
long long dp[1 << 16];

long long solv() {
  int i, j, g[121];

  for (i = 0; i < n; i++) {
    g[i] = 0;
  }
  for (i = 0; i < (1 << n); i++) {
    dp[i] = 0;
  }
  for (i = 0; i < m; i++) {
    g[y[i]] |= 1 << x[i];
  }

  dp[0] = 1;
  for (i = 0; i < (1 << n); i++) {
    for (j = 0; j < n; j++) {
      if ((i & g[j]) == g[j] && (i & (1 << j)) == 0) {
        dp[i | (1 << j)] += dp[i];
      }
    }
  }
  // for (i = 0; i < (1 << n); i++) {
  //   printf("%d: %lld\n", i, dp[i]);
  // }

  return dp[(1 << n) - 1];
}

int main(int argc, char **argv) {
  int i;

  while (scanf("%d %d", &n, &m) != EOF) {
    for (i = 0; i < m; i++) {
      scanf("%d %d", &x[i], &y[i]);
      x[i]--;
      y[i]--;
    }

    printf("%lld\n", solv());
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:41:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d %d", &x[i], &y[i]);
       ^
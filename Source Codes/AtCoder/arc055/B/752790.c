#include <stdio.h>
#include <string.h>

double dp[1001][1001];
int N, K;
double f(int n, int k) {
  if (dp[n][k] >= 0) return dp[n][k];
  double pn = 1.0 / (N - n + 1);
  double nnp = f(n - 1, k);
  double np = 1.0 / N + pn * f(n - 1, k - 1) + (1 - pn) * nnp;
  dp[n][k] = nnp;
  if (dp[n][k] < np) dp[n][k] = np;
  return dp[n][k];
}

int main() {
  scanf("%d %d", &N, &K);
  memset(dp, -1.0, sizeof(dp));
  for (int i = 0; i <= N; ++i) {
    dp[i][i] = 1.0 * i / N;
    dp[i][0] = 0;
  }
  printf("%.15lf\n", f(N, K));
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
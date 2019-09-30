#include <stdio.h>
#include <string.h>

double dp[1001][1001];
N, K, i;
double f(short n, short k) {
  if (dp[n][k] >= 0) return dp[n][k];
  double pn = 1.0 / (N - n + 1);
  double np = 1.0 / N + pn * f(n - 1, k - 1) + (1 - pn) * f(n - 1, k);
  dp[n][k] = f(n - 1, k);
  if (dp[n][k] < np) dp[n][k] = np;
  return dp[n][k];
}

main() {
  scanf("%d %d", &N, &K);
  memset(dp, -1.0, sizeof(dp));
  for (i = 0; i <= N; ++i) {
    dp[i][i] = 1.0 * i / N;
    dp[i][0] = 0;
  }
  printf("%.8lf\n", f(N, K));
} ./Main.c:5:1: warning: data definition has no type or storage class
 N, K, i;
 ^
./Main.c:5:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:5:4: warning: type defaults to ‘int’ in declaration of ‘K’ [-Wimplicit-int]
 N, K, i;
    ^
./Main.c:5:7: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 N, K, i;
       ^
./Main.c:15:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main() {
 ^
./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &K);
   ^
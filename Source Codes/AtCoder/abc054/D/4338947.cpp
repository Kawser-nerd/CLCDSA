#include <cstdio>
#include <vector>
#include <algorithm>

template <class Tp>
Tp& chmin(Tp& dst, const Tp& src) {
  if (src < dst) dst = src;
  return dst;
}

template <class Tp>
Tp& chmax(Tp& dst, const Tp& src) {
  if (dst < src) dst = src;
  return dst;
}

int main() {
  size_t N;
  int Ma, Mb;
  scanf("%zu %d %d", &N, &Ma, &Mb);

  std::vector<int> a(N), b(N), c(N);
  for (size_t i = 0; i < N; ++i)
    scanf("%d %d %d", &a[i], &b[i], &c[i]);

  int INF = 1e9;
  int M = 400;
  std::vector<std::vector<std::vector<int>>> dp(
      N+1, std::vector<std::vector<int>>(
        M+1, std::vector<int>(M+1, INF)));

  dp[0][0][0] = 0;
  for (size_t i = 1; i <= N; ++i) {
    for (int j = 0; j <= M; ++j)
      for (int k = 0; k <= M; ++k) {
        dp[i][j][k] = std::min(dp[i][j][k], dp[i-1][j][k]);
        if (a[i-1] <= j && b[i-1] <= k)
          chmin(dp[i][j][k], dp[i-1][j-a[i-1]][k-b[i-1]]+c[i-1]);
      }
  }

  int res = INF;
  for (int j = 1; j <= M; ++j)
    for (int k = 1; k <= M; ++k)
      if (j*Mb == k*Ma)
        chmin(res, dp[N][j][k]);

  if (res == INF) return puts("-1"), 0;
  printf("%d\n", res);
}
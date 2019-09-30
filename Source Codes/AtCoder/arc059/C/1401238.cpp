#include <iostream>
#include <vector>

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned N, C;
  std::cin >> N >> C;
  std::vector<std::vector<unsigned long long>> fact_sum(401ul, std::vector<unsigned long long>(401));
  for (auto &i : fact_sum) { i[0] = 1; }
  for (unsigned i = 0; i < 401u; ++i) {
    for (unsigned j = 1; j < 401u; ++j) {
      fact_sum[i][j] = fact_sum[i][j - 1] * i;
      fact_sum[i][j] %= MOD;
    }
  }
  for (unsigned i = 1; i < 401u; ++i) {
    for (unsigned j = 0; j < 401u; ++j) {
      fact_sum[i][j] += fact_sum[i - 1][j];
      fact_sum[i][j] %= MOD;
    }
  }
  std::vector<unsigned> A(N + 1);
  std::vector<unsigned> B(N + 1);
  for (unsigned i = 1; i <= N; ++i) { std::cin >> A[i]; }
  for (unsigned i = 1; i <= N; ++i) { std::cin >> B[i]; }
  std::vector<std::vector<unsigned long long>> dp(N + 1, std::vector<unsigned long long>(C + 1, 0));
  dp[0][0] = 1;
  for (unsigned i = 1; i <= N; ++i) {
    for (unsigned j = 0; j <= C; ++j) {
      for (unsigned k = 0; k <= j; ++k) {
        auto x = fact_sum[B[i]][k] > fact_sum[A[i] - 1][k] ? fact_sum[B[i]][k] : fact_sum[B[i]][k] + MOD;
        x -= fact_sum[A[i] - 1][k];
        dp[i][j] += dp[i - 1][j - k] * x;
        dp[i][j] %= MOD;
      }
    }
  }
  std::cout << dp[N][C] << std::endl;
  return 0;
}
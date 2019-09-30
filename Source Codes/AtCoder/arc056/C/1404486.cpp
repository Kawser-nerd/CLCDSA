#include <iostream>
#include <vector>

int main() {
  unsigned N;
  long long K;
  std::cin >> N >> K;
  std::vector<std::vector<int>> w(N, std::vector<int>(N));
  for (unsigned i = 0; i < N; ++i) {
    for (unsigned j = 0; j < N; ++j) {
      std::cin >> w[i][j];
    }
  }
  std::vector<long long> clq(1ul << N, 0);
  for (unsigned i = 0; i < (1u << N); ++i) {
    for (unsigned j = 0; j < N; ++j) {
      if (i & (1u << j)) {
        for (unsigned k = j + 1; k < N; ++k) {
          if (i & (1u << k)) {
            clq[i] += w[j][k];
          }
        }
      }
    }
  }
  std::vector<long long> dp(1ul << N, 0);
  for (unsigned i = 0; i < (1u << N); ++i) {
    for (unsigned j = i; j > 0; j = (j - 1) & i) {
      dp[i] = std::max(dp[i], dp[i ^ j] + K - (clq[i] - clq[j] - clq[i ^ j]));
    }
  }
  std::cout << dp[(1u << N) - 1] << std::endl;
  return 0;
}
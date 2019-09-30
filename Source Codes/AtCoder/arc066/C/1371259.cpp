#include <iostream>
#include <vector>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<long long> A(N);
  std::vector<char> op(N);
  op[0] = '+';
  std::cin >> A[0];
  for (unsigned i = 1; i < N; ++i) {
    std::cin >> op[i] >> A[i];
  }
  std::vector<std::vector<long long>> dp(N, std::vector<long long>(3));
  dp[0][0] = A[0];
  dp[0][1] = std::numeric_limits<long long>::min() / 2;
  dp[0][2] = std::numeric_limits<long long>::min() / 2;
  for (unsigned i = 1; i < N; ++i) {
    if (op[i] == '+') {
      dp[i][0] = std::max(dp[i - 1][0] + A[i], dp[i - 1][1] + A[i]);
      dp[i][1] = std::max(dp[i - 1][1] - A[i], dp[i - 1][2] - A[i]);
      dp[i][2] = dp[i - 1][2] + A[i];
    } else {
      dp[i][0] = std::max(dp[i - 1][0] - A[i], dp[i - 1][1] - A[i]);
      dp[i][1] = std::max(std::max(dp[i - 1][0] - A[i], dp[i - 1][2] + A[i]), dp[i - 1][1] + A[i]);
      dp[i][2] = std::max(dp[i - 1][1] + A[i], dp[i - 1][2] + A[i]);
    }
  }
  std::cout << std::max(std::max(dp.back()[0], dp.back()[1]), dp.back()[2]);
  return 0;
}
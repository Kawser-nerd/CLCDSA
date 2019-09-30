#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

constexpr intmax_t MOD = 1e9+7;

int main() {
  size_t H, W, K;
  scanf("%zu %zu %zu", &H, &W, &K);

  std::vector<std::vector<intmax_t>> dp(H+1, std::vector<intmax_t>(W));
  dp[0][0] = 1;

  for (size_t i = 0; i < H; ++i) {
    for (size_t j = 0; j < W; ++j) {
      for (int k = 0; k < (1 << (W-1)); ++k) {
        if (k & (k >> 1)) continue;
        if (j+1 < W && k >> j & 1) {
          (dp[i+1][j+1] += dp[i][j]) %= MOD;
        } else if (j > 0 && k >> (j-1) & 1) {
          (dp[i+1][j-1] += dp[i][j]) %= MOD;
        } else {
          (dp[i+1][j] += dp[i][j]) %= MOD;
        }
      }
    }
  }
  printf("%jd\n", dp[H][K-1]);
}
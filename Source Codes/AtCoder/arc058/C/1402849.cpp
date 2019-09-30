#include <iostream>
#include <vector>

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned N, X, Y, Z;
  std::cin >> N >> X >> Y >> Z;
  unsigned mask = (1u << (X + Y + Z - 1)) | (1u << (Y + Z - 1)) | (1u << (Z - 1));
  std::vector<std::vector<unsigned long long>> dp(N + 1, std::vector<unsigned long long>(1u << (X + Y + Z), 0));
  dp[0][0] = 1;
  unsigned HOGE = X + Y + Z - 1;
  for (unsigned i = 0; i < N; ++i) {
    unsigned j = 0;
    for (unsigned k = 0; k <= (X + Y + Z); ++k) {
      for (; j < 1u << k; ++j) {
        for (unsigned l = 0; l < 10; ++l) {
          if (l + k > HOGE) {
            unsigned x = ((1u << (l + k)) + j) >> (l + k - HOGE);
            if ((x & mask) != mask || !(j & 1u << (l + k - HOGE - 1))) {
              dp[i + 1][x] += dp[i][j];
              dp[i + 1][x] %= MOD;
            }
          } else {
            unsigned x = (1u << (l + k)) + j;
            if ((x & mask) != mask) {
              dp[i + 1][x] += dp[i][j];
              dp[i + 1][x] %= MOD;
            }
          }
        }
      }
    }
  }
  unsigned long long ans = 0;
  for (unsigned i = 0; i < 1u << (X + Y + Z); ++i) {
    ans += dp[N][i];
    ans %= MOD;
  }
  unsigned long long all = 1;
  for (unsigned i = 0; i < N; ++i) {
    all *= 10;
    all %= MOD;
  }
  std::cout << (all >= ans ? all - ans : all + MOD - ans) << std::endl;
  return 0;
}
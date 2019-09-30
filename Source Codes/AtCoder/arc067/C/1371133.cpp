#include <iostream>
#include <vector>

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned long N;
  unsigned long long A, B, C, D;
  std::cin >> N >> A >> B >> C >> D;
  std::vector<unsigned long long> inv(N + 1);
  inv[1] = 1;
  for (unsigned i = 2; i <= N; ++i) { inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD; }
  std::vector<unsigned long long> fact(N + 1);
  fact[0] = 1;
  for (unsigned i = 1; i <= N; ++i) { fact[i] = fact[i - 1] * i % MOD; }
  std::vector<unsigned long long> inv_fact(N + 1);
  inv_fact[0] = 1;
  for (unsigned i = 1; i <= N; ++i) { inv_fact[i] = inv_fact[i - 1] * inv[i] % MOD; }
  std::vector<std::vector<unsigned long long>> dp(N + 1, std::vector<unsigned long long>(N + 1, 0));
  for (unsigned i = 0; i <= N; ++i) { dp[0][i] = 1; }
  for (unsigned i = 1; i <= N; ++i) {
    for (auto j = A; j <= B; ++j) {
      dp[i][j] = dp[i][j - 1];
      if (i / j < C) { continue; }
      unsigned long long tmp = 1;
      for (unsigned k = 0; k < C - 1; ++k) {
        tmp *= inv_fact[j];
        tmp %= MOD;
      }
      for (auto k = C; k <= std::min(i / j, D); ++k) {
        tmp *= inv_fact[j];
        tmp %= MOD;
        auto acc = dp[i - k * j][j - 1];
        //choose{i}{k*j} * frac{(k*j)!}{j!**k*k!}
        //i!(k*j)! / (k*j)!(i-k*j)!(j!)**k(k!)
        //i! / (i-k*j)!(j!)**k(k!)
        acc *= fact[i];
        acc %= MOD;
        acc *= inv_fact[i - k * j];
        acc %= MOD;
        acc *= tmp;
        acc %= MOD;
        acc *= inv_fact[k];
        acc %= MOD;
        dp[i][j] += acc;
        dp[i][j] %= MOD;
      }
    }
  }
  std::cout << dp[N][B];
  return 0;
}
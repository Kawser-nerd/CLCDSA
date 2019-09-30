#include <iostream>
#include <vector>

int main() {
  const unsigned long long MOD = 1000000007;
  unsigned long long N;
  std::cin >> N;
  std::vector<unsigned long long> f(N + 1, 0);
  std::vector<bool> b(N + 1, false);
  for (auto i = 1ull; i <= N; ++i) {
    for (auto j = 2ull; j < i; ++j) {
      if (b[j]) { continue; }
      if (i % j == 0) {
        b[i] = true;
        ++f[j];
        auto x = i / j;
        while (x % j == 0) {
          ++f[j];
          x /= j;
        }
      }
    }
    if (!b[i]) { f[i] = 1; }
    else { f[i] = 0; }
  }
  auto ans = 1ull;
  for (auto i = 2ull; i <= N; ++i) {
    ans *= f[i] + 1;
    ans %= MOD;
  }
  std::cout << ans << std::endl;
  return 0;
}
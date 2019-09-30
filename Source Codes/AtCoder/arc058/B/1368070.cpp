#include <iostream>
#include <vector>

int main() {
  const unsigned long long mod = 1000000007;
  unsigned long long h, w, a, b;
  std::cin >> h >> w >> a >> b;
  std::vector<unsigned long long> inv(h + w + 1);
  inv[1] = 1;
  for (unsigned i = 2; i <= h + w; ++i) {
    inv[i] = mod - (mod / i) * inv[mod % i] % mod;
  }
  std::vector<unsigned long long> fact(h + w + 1);
  fact[0] = 1;
  for (unsigned i = 1; i <= h + w; ++i) {
    fact[i] = fact[i - 1] * i % mod;
  }
  std::vector<unsigned long long> inv_fact(h + w + 1);
  inv_fact[0] = 1;
  for (unsigned i = 1; i <= h + w; ++i) {
    inv_fact[i] = inv_fact[i - 1] * inv[i] % mod;
  }
  unsigned long long ans = 0ull;
  for (unsigned i = 1; i <= h - a; ++i) {
    auto x = fact[i - 1 + b - 1];
    x *= inv_fact[i - 1];
    x %= mod;
    x *= inv_fact[b - 1];
    x %= mod;
    auto y = fact[h - i + w - b - 1];
    y *= inv_fact[h - i];
    y %= mod;
    y *= inv_fact[w - b - 1];
    y %= mod;
    ans += x * y % mod;
    ans %= mod;
  }
  std::cout << ans;
  return 0;
}
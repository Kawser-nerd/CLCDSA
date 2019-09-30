#include <array>
#include <iostream>
using namespace std;

constexpr uint64_t mod = 1e9 + 7;

template <int N> constexpr array<uint64_t, N + 1> factorial_table() {
  array<uint64_t, N + 1> ans;
  ans[0] = 1;
  for (int i = 1; i <= N; i++)
    ans[i] = i;
  for (int i = 2; i <= N; i++) {
    ans[i] = (ans[i] * ans[i - 1]) % mod;
  }
  return ans;
}

constexpr uint64_t mod_pow(uint64_t num, uint64_t p) {
  uint64_t ans = 1;
  num %= mod;
  while (0 < p) {
    if (p & 1) {
      ans = (ans * num) % mod;
    }
    num = (num * num) % mod;
    p >>= 1;
  }
  return ans;
}

template <int N>
constexpr array<uint64_t, N + 1> inv_table(const array<uint64_t, N + 1> &fct) {
  array<uint64_t, N + 1> ans;
  ans[N] = mod_pow(fct[N], mod - 2);
  for (int i = N - 1; 0 <= i; i--)
    ans[i] = ((uint64_t)ans[i + 1] * (i + 1)) % mod;
  return ans;
}

template <typename table>
uint64_t comb(const table &factorial, const table &inv, uint64_t x,
              uint64_t y) {
  if (x == 0 || y == 0)
    return 1;
  return (((uint64_t)factorial[x] * inv[y]) % mod) * inv[x - y] % mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  const auto table = factorial_table<200005>();
  const auto inv = inv_table<200005>(table);
  uint64_t w, h;
  cin >> w >> h;

  auto combination = [&](uint64_t x, uint64_t y) {
    return comb(table, inv, x + y, y);
  };
  auto ans = combination(w - 1, h - 1);

  cout << ans << "\n";
}
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

constexpr intmax_t MOD = 1e9+7;

intmax_t f(const std::vector<intmax_t>& a) {
  size_t n = a.size();
  std::vector<intmax_t> b(n-1);
  for (size_t i = 1; i < n; ++i)
    b[i-1] = a[i] - a[i-1];

  intmax_t res = 0;
  intmax_t sum = 0;
  for (size_t i = 0; i+1 < n; ++i) {
    intmax_t j = i+1;
    sum += j * b[i] % MOD;
    (res += sum) %= MOD;
  }
  return res;
}

int main() {
  size_t n, m;
  scanf("%zu %zu", &n, &m);

  std::vector<intmax_t> x(n), y(m);
  for (auto& xi: x) scanf("%jd", &xi);
  for (auto& yj: y) scanf("%jd", &yj);

  intmax_t xs = f(x);
  intmax_t ys = f(y);
  printf("%jd\n", xs*ys % MOD);
}
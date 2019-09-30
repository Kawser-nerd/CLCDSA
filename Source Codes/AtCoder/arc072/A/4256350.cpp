#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <algorithm>

bool same_sign(intmax_t m, intmax_t n) {
  if (m < 0 && n < 0) return true;
  if (m > 0 && n > 0) return true;
  return false;
}

intmax_t f(const std::vector<int>& a, const std::vector<int>& b) {
  intmax_t res = 0;
  intmax_t sum = 0;
  for (size_t i = 0; i < a.size(); ++i) {
    if (same_sign(sum+a[i], b[i])) {
      sum += a[i];
    } else {
      res += abs(sum+a[i]-b[i]);
      sum = b[i];
    }
  }
  return res;
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<int> a(n);
  for (auto& ai: a) scanf("%d", &ai);

  std::vector<int> b(n, 1);
  for (size_t i = 0; i < n; i += 2) b[i] = -1;

  intmax_t res = f(a, b);
  for (auto& bi: b) bi = -bi;
  res = std::min(res, f(a, b));
  printf("%jd\n", res);
}
#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

std::vector<intmax_t> divisor(intmax_t n) {
  std::vector<intmax_t> res;
  for (intmax_t i = 1; i*i <= n; ++i) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n/i)
        res.push_back(n/i);
    }
  }
  std::sort(res.begin(), res.end());
  return res;
}

intmax_t digitsum(intmax_t n, intmax_t base=10) {
  intmax_t res = 0;
  for (; n; n /= base) res += n % base;
  return res;
}

int main() {
  intmax_t n, s;
  scanf("%jd %jd", &n, &s);

  if (n == s)
    return !printf("%jd\n", n+1);

  for (intmax_t b = 2; b*b <= n; ++b)
    if (digitsum(n, b) == s)
      return !printf("%jd\n", b);

  for (auto b1: divisor(n-s))
    if (digitsum(n, b1+1) == s)
      return !printf("%jd\n", b1+1);

  puts("-1");
}
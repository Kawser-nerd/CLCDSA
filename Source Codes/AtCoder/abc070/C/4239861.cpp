#include <cstdio>
#include <cstdint>
#include <algorithm>

intmax_t gcd(intmax_t m, intmax_t n) {
  while (n) std::swap(m %= n, n);
  return m;
}

intmax_t lcm(intmax_t m, intmax_t n) {
  return m / gcd(m, n) * n;
}

int main() {
  int N;
  scanf("%d", &N);

  intmax_t res = 1;
  for (int i = 0; i < N; ++i) {
    intmax_t T;
    scanf("%jd", &T);
    res = lcm(res, T);
  }
  printf("%jd\n", res);
}
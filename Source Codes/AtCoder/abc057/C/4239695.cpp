#include <cstdio>
#include <cstdint>
#include <algorithm>

intmax_t digits(intmax_t n) {
  intmax_t res = 0;
  for (intmax_t i = n; i; i /= 10) ++res;
  return res;
}

int main() {
  intmax_t N;
  scanf("%jd", &N);

  intmax_t res = 20;
  for (intmax_t A = 1; A*A <= N; ++A) {
    if (N % A != 0) continue;

    intmax_t B = N / A;
    res = std::min(res, std::max(digits(A), digits(B)));
  }
  printf("%jd\n", res);
}
#include <cstdio>
#include <cstdint>
#include <utility>

intmax_t gcd(intmax_t m, intmax_t n) {
  while (n) std::swap(m %= n, n);
  return m;
}

int main() {
  int N;
  scanf("%d", &N);

  intmax_t t = 1;
  intmax_t a = 1;
  for (int i = 0; i < N; ++i) {
    int T, A;
    scanf("%d %d", &T, &A);

    intmax_t t0 = (t+T-1)/T*T;
    intmax_t a0 = A*(t0/T);

    intmax_t a1 = (a+A-1)/A*A;
    intmax_t t1 = T*(a1/A);

    if (a0 < a) {
      t = t1;
      a = a1;
    } else {
      t = t0;
      a = a0;
    }
  }
  printf("%jd\n", t+a);
}
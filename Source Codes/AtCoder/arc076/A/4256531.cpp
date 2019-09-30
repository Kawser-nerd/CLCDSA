#include <cstdio>
#include <cstdint>
#include <cstdlib>

constexpr intmax_t MOD = 1e9+7;

intmax_t fact(intmax_t n) {
  intmax_t res = 1;
  for (intmax_t i = 2; i <= n; ++i)
    (res *= i) %= MOD;
  return res;
}

int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  if (abs(N-M) > 1)
    return puts("0"), 0;

  intmax_t res = 1;
  if (N == M) {
    res = fact(N) * fact(N) % MOD;
    (res *= 2) %= MOD;
  } else {
    res = fact(N) * fact(M) % MOD;
  }
  printf("%jd\n", res);
}
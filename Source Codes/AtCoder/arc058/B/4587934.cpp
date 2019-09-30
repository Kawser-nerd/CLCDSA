#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>

constexpr intmax_t MOD = 1e9+7;

template <class Tp>
Tp gcd(Tp a, Tp b, Tp& x, Tp& y) {
  x = Tp(0);
  y = Tp(1);
  for (Tp u=y, v=x; a;) {
    Tp q = b/a;
    std::swap(x-=q*u, u);
    std::swap(y-=q*v, v);
    std::swap(b-=q*a, a);
  }
  return b;
}

template <class Tp>
Tp modinv(Tp a, Tp mod) {
  Tp x, y;
  gcd(a, mod, x, y);
  x %= mod;
  if (x < 0) x += mod;
  return x;
}

class modchoose {
  std::vector<intmax_t> fact, fact_inv;
  intmax_t mod;

public:
  modchoose(intmax_t N, intmax_t mod): mod(mod) {
    fact.resize(N+1);
    fact_inv.resize(N+1);
    fact[0] = 1;
    for (intmax_t i = 1; i <= N; ++i)
      fact[i] = fact[i-1] * i % MOD;

    fact_inv[N] = modinv(fact[N], mod);
    for (intmax_t i = N; i--;)
      fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
  }

  intmax_t operator ()(intmax_t n, intmax_t r) const {
    intmax_t res = fact[n] * fact_inv[r] % mod;
    (res *= fact_inv[n-r]) %= mod;
    return res;
  }
};

int main() {
  intmax_t H, W, A, B;
  scanf("%jd %jd %jd %jd", &H, &W, &A, &B);

  modchoose ncr(H+W, MOD);
  intmax_t res = 0;
  for (intmax_t i = 0; i < W-B; ++i)
    (res += ncr(H-A-1+B+i, B+i) * ncr(A+W-B-2-i, A-1)) %= MOD;

  printf("%jd\n", res);
}
#include <cstdio>
#include <cstdint>
#include <cassert>
#include <vector>
#include <algorithm>

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

template <class Tp>
Tp modsub(Tp a, Tp b, Tp mod) {
  a -= b % mod;
  if (a < 0) a += mod;
  if (a >= mod) a -= mod;
  return a;
}

template <class Tp>
Tp modmul(const std::initializer_list<Tp>& muls, Tp mod) {
  Tp res = 1;
  for (const auto& mul: muls) (res *= mul) %= mod;
  return res;
}

class modfactorial {
  std::vector<intmax_t> fact, fact_inv;
  intmax_t mod;

public:
  modfactorial(intmax_t N, intmax_t mod): mod(mod) {
    fact.resize(N+1);
    fact_inv.resize(N+1);
    fact[0] = 1;
    for (intmax_t i = 1; i <= N; ++i)
      fact[i] = fact[i-1] * i % mod;

    fact_inv[N] = modinv(fact[N], mod);
    for (intmax_t i = N; i--;)
      fact_inv[i] = fact_inv[i+1] * (i+1) % mod;
  }

  intmax_t operator ()(intmax_t k) const {
    return fact[k];
  }

  intmax_t inverse(intmax_t k) const {
    return fact_inv[k];
  }
};

intmax_t interpolate(const std::vector<intmax_t>& y, intmax_t x, intmax_t mod) {
  // based on Lagrange interpolation
  // y[i] = f(i) where i in [0, n]
  assert(0 <= x);

  intmax_t n = y.size()-1;
  if (x <= n) return y[x];

  modfactorial mf(n, mod);
  intmax_t omega = 1;
  for (intmax_t j = 0; j <= n; ++j)
    (omega *= (x-j)) %= mod;

  intmax_t sigma = 0;
  for (intmax_t i = 0; i <= n; ++i) {
    intmax_t wi = modmul({mf.inverse(i), mf.inverse(n-i)}, mod);
    if ((n-i) % 2 != 0) wi = mod-wi;
    (sigma += modmul({y[i], wi, modinv(x-i, mod)}, mod)) %= mod;
  }

  return modmul({sigma, omega}, mod);
}

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> a(n+1);
  for (auto& ai: a) scanf("%jd", &ai);

  intmax_t t;
  scanf("%jd", &t);

  constexpr intmax_t MOD = 1e9+7;
  printf("%jd\n", interpolate(a, t, MOD));
}
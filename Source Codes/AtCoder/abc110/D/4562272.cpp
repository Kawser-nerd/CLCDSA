#include <cstdio>
#include <cstdint>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>

constexpr intmax_t MOD = 1e9+7;

std::map<intmax_t, intmax_t> factor(intmax_t n) {
  std::map<intmax_t, intmax_t> res;
  for (intmax_t i = 2; i*i <= n; ++i) {
    while (n % i == 0) {
      ++res[i];
      n /= i;
    }
  }
  if (n > 1) ++res[n];
  return res;
}

template <class Tp>
Tp gcd(Tp a, Tp b, Tp& x, Tp& y) {
  x = Tp(0);
  y = Tp(1);
  for (Tp u = y, v = x; a;) {
    Tp q = b/a;
    std::swap(x -= q*u, u);
    std::swap(y -= q*v, v);
    std::swap(b -= q*a, a);
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
  intmax_t N, M;
  scanf("%jd %jd", &N, &M);

  modchoose ncr(200000, MOD);

  intmax_t res = 1;
  for (const auto& p: factor(M))
    (res *= ncr(p.second+N-1, N-1)) %= MOD;

  printf("%jd\n", res);
}
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const int MAXF = 200000;
const int MOD  = 1000000007;

ll f[MAXF + 5], invf[MAXF + 5];

inline ll lgput(ll a, ll n) {
  ll res = 1;
  while (n > 0) {
    if (n % 2 == 1)
      res = 1LL * res * a % MOD;
    a = 1LL * a * a % MOD;
    n /= 2;
  }
  return res;
}

inline ll comb(ll n, ll k) {
  if (n < k) {
    return 0;
  } else if (n < 0 || k < 0) {
    return 0;
  } else {
    return 1LL * f[n] % MOD * invf[n - k] % MOD * invf[k] % MOD;
  }
}

vector<pair<ll, ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (ll p = 2; p * p <= n; p++) {
    if (n % p != 0)
      continue;
    int num = 0;
    while (n % p == 0) {
      num++;
      n /= p;
    }
    res.push_back(make_pair(p, num));
  }
  if (n != 1)
    res.push_back(make_pair(n, 1));
  return res;
}

int main() {
  ll N, M;
  cin >> N >> M;

  f[0]    = 1;
  invf[0] = 1;
  for (int i = 1; i <= MAXF; i++) {
    f[i] = f[i - 1] * i % MOD;
  }
  invf[MAXF] = 1LL * lgput(f[MAXF], MOD - 2) % MOD;
  for (int i = MAXF - 1; i >= 1; i--) {
    invf[i] = 1LL * invf[i + 1] * (i + 1) % MOD;
  }

  auto vec = prime_factorize(M);
  ll res   = 1;
  for (auto p : vec) {
    ll num = p.second;
    ll tmp = comb(num + N - 1, N - 1) % MOD;
    res    = res * tmp % MOD;
  }

  cout << res << endl;
  return 0;
}
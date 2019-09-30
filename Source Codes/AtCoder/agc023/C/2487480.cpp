#include <iostream>
 
#define ll long long
#define MOD 1000000007
 
#define MODA(a, b) ((a + b) % MOD)
#define MODS(a, b) (((a - b) % MOD + MOD) % MOD)
#define MODM(a, b) (a * b % MOD)
 
ll power_mod(ll x, ll n) {
  if (n == 0)
    return 1;
  else if (n % 2)
    return MODM(x, power_mod(x, n - 1));
  else
    return power_mod(MODM(x, x), n / 2);
}
 
ll facts[1000000];
ll rfacts[1000000];
 
ll comb(ll n, ll k) {
  if (n == 0 || k == 0 || n - k == 0) return 1;
  return MODM(MODM(facts[n], rfacts[k]), rfacts[n - k]);
}
 
int main() {
  int upper = 1000000;
 
  ll f = 1;
  facts[0] = 1;
  for (int i = 1; i <= upper; i++) {
    f = MODM(f, i);
    facts[i] = f;
    rfacts[i] = power_mod(f, MOD - 2);
  }
 
  //???comb()?????
  int n;
  std::cin >> n;
 
  ll res = 0;
  ll pre = 0;
  for (int k = (n - 1) / 2 + 1; k < n; k++) {
    ll cnt = MODM(MODM(comb(k - 1, n - k - 1), facts[k]), facts[n - k - 1]);
 
    res = MODA(res, MODM(k, MODS(cnt, pre)));
    pre = cnt;
  }
 
  std::cout << res << std::endl;
 
  return 0;
}
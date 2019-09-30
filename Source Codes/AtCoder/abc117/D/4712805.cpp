#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define vec vector
#define pb push_back
#define ll long long
#define ALL(a) a.begin(), a.end()

int main(void)
{
  ll n, k;
  cin >> n >> k;
  vec<ll> m(48, 0);
  rep(i, 48) m[i] = ((k + 1) >> i) % 2;

  vec<ll> a(n);
  rep(i, n) cin >> a[i];

  vec<ll> keta(48, 0);
  rep(i, n) {
    rep(j, 48) keta[j] += (a[i] >> j) % 2;
  }

  ll Max = 0;
  rep(i, 48) Max += ((ll)1 << (ll)i) * keta[i];
  rep(i, 48) {
    if (!m[i]) continue;
    vec<ll> x(48);
    rep(j, i) x[j] = max(keta[j], n - keta[j]);
    x[i] = keta[i];
    for (int j = i + 1; j < 48; j++) x[j] = m[j] ? n - keta[j] : keta[j];
    ll temp = 0;
    rep(j, 48) temp += ((ll)1 << (ll)j) * x[j];
    if (temp > Max) Max = temp;
  }
  cout << Max << endl;
  return 0;
}
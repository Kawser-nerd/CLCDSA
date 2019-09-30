#include <algorithm>
#include <iostream>
#include <vector>

using ll = long long int;
const ll INF = 1e18;

int main() {
  int a, b, q;
  std::cin >> a >> b >> q;
  std::vector<ll> s;
  std::vector<ll> t;
  s.push_back(-INF);
  t.push_back(-INF);
  for (int i = 0; i < a; i++) {
    ll x;
    std::cin >> x;
    s.push_back(x);
  }
  for (int i = 0; i < b; i++) {
    ll x;
    std::cin >> x;
    t.push_back(x);
  }
  s.push_back(INF);
  t.push_back(INF);

  for (int i = 0; i < q; i++) {
    long long int x;
    std::cin >> x;
    ll ns = std::upper_bound(s.begin(), s.end(), x) - s.begin() - 1;
    ll nsp = std::lower_bound(s.begin(), s.end(), x) - s.begin();
    ll nt = std::upper_bound(t.begin(), t.end(), x) - t.begin() - 1;
    ll ntp = std::lower_bound(t.begin(), t.end(), x) - t.begin();
    std::vector<ll> ss = {s[ns], s[nsp]};
    std::vector<ll> tt = {t[nt], t[ntp]};
    ll ans = INF;
    for (auto s : ss) {
      for (auto t : tt) {
        ll d1 = std::abs(s - x) + std::abs(t - s);
        ll d2 = std::abs(t - x) + std::abs(s - t);
        ans = std::min(ans, std::min(d1, d2));
      }
    }
    std::cout << ans << std::endl;
  }
}
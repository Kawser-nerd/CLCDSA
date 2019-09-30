#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n;
  cin >> n;
  vector<ll> ls(n);
  for (auto& l : ls) {
    cin >> l;
  }

  ll ans = 0;
  
  bool flag = true;
  while (flag) {
    flag = false;
    for (auto& l : ls) {
      if (l > n - 1) {
        flag = true;
        ll m = l / n;
        l = l % n;
        for (auto& l2 : ls) {
          l2 += m;
        }
        l -= m;
        ans += m;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
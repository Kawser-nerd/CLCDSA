// Last Change: 04/05/2019 03:20:10.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

ll N, M;
vector<ll> x;
vector<ll> y;
vector<ll> z;

ll Cal(ll depth, int pos) {
  if (depth == 3) {
    vector<ll> tmp(N, 0);
    for (ll i = 0; i < N; ++i) {
      if (pos & (1 << 2)) {
        tmp[i] += x[i];
      } else {
        tmp[i] -= x[i];
      }
      if (pos & (1 << 1)) {
        tmp[i] += y[i];
      } else {
        tmp[i] -= y[i];
      }
      if (pos & 1) {
        tmp[i] += z[i];
      } else {
        tmp[i] -= z[i];
      }
    }
    sort(tmp.begin(), tmp.end(), std::greater<ll>());

    ll ans = 0;
    for (ll i = 0; i < M; ++i) {
      ans += tmp[i];
    }
    return ans;
  }
  ll ans = Cal(depth + 1, (pos << 1));
  ans = max(ans, Cal(depth + 1, (pos << 1) | 1));
  return ans;
}

int main() {
  cin >> N >> M;
  x.resize(N);
  y.resize(N);
  z.resize(N);
  for (ll i = 0; i < N; ++i) {
    cin >> x[i] >> y[i] >> z[i];
  }

  ll ans = Cal(0, 0);
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
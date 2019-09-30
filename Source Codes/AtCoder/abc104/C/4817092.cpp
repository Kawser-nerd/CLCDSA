// Last Change: 04/04/2019 00:25:29.
/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
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

ll D, G;
vector<int> p;
vector<ll> c;

ll Cal(ll val, ll ans, ll depth, int which) {
  if (val >= G) {
    return ans;
  }

  if (depth == D) {
    for (int i = D; i >= 1; --i) {
      if ((which >> (D - i)) & 1) {
        // do nothing
      } else {
        ll diff = G - val;
        if (diff > (i * (p[i - 1] - 1))) {
          val += i * (p[i - 1] - 1);
          ans += p[i - 1] - 1;
        } else {
          ans += diff / i;
          if ((diff % i) > 0) {
            ++ans;
          }
          return ans;
        }
      }
    }
    if (val < G) {
      return numeric_limits<ll>::max();
    }
  }

  ll high, low;
  low = Cal(val, ans, depth + 1, which << 1);

  val += (depth + 1) * p[depth] + c[depth];
  ans += p[depth];
  high = Cal(val, ans, depth + 1, (which << 1) | 1);

  return min(high, low);
}

int main() {
  cin >> D >> G;
  G /= 100;
  p.resize(D);
  c.resize(D);

  for (int i = 0; i < D; ++i) {
    ll ipt;
    cin >> p[i] >> ipt;
    c[i] = ipt / 100;
  }

  ll ans = Cal(0, 0, 0, 0);
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
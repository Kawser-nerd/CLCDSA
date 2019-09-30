// Last Change: 02/20/2019 23:53:28.
///////////////////////////////////////////////////////////////////////////
//  ?????????????????????OK
//  ????
//    ??????X?
//    ??????Y?
//    X?Y??????????
//  ???????????
//  ???????for???Y????????????????
//    Y>{(N-X)E-H-BX}/(D+E)
//    ???????Y???????
//  ???????????????
///////////////////////////////////////////////////////////////////////////
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

int main() {
  ll N, H, A, B, C, D, E;
  cin >> N >> H;
  cin >> A >> B >> C >> D >> E;

  int64_t ans = INT64_MAX;

  //???????????????1??????
  /*
  int64_t tmp;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N - i; ++j) {
      if (i * B + j * D + H > E * (N - i - j)) {
        tmp = i * A + j * C;
        ans = min(ans, tmp);
        break;
      }
    }
  }*/
  for (ll i = 0; i <= N; ++i) {
    ll bunbo = (N - i) * E - H - B * i;
    ll de = D + E;
    ll j;
    if (bunbo < 0) {
      j = 0;
    } else {
      j = static_cast<ll>(bunbo / de);
      ++j;
    }
    if (i + j <= N) {
      int64_t tmpAns = i * A + j * C;
      ans = min(ans, tmpAns);
    }
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
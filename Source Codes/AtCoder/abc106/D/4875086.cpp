// Last Change: 04/07/2019 17:31:47.
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
  ll N, M, Q;
  cin >> N >> M >> Q;

  vector<vector<ll>> station(N + 1, vector<ll>(N + 1, 0));
  ll l, r;
  for (ll i = 0; i < M; ++i) {
    cin >> l >> r;
    ++station[l][r];
  }

  //??station?????????????station[i][j]+=station[i-1][j]...
  vector<vector<ll>> cumSum(N + 1, vector<ll>(N + 1, 0));
  for (ll i = 1; i < N + 1; ++i) {
    for (ll j = 1; j < N + 1; ++j) {
      cumSum[i][j] = cumSum[i - 1][j] + cumSum[i][j - 1] - cumSum[i - 1][j - 1]
                     + station[i][j];
    }
  }

  for (ll i = 0; i < Q; ++i) {
    cin >> l >> r;
    ll ans = cumSum[r][r] - cumSum[r][l - 1] - cumSum[l - 1][r]
             + cumSum[l - 1][l - 1];
    cout << ans << endl;
  }

  //NS::LoopUntilZeroInpput();
}
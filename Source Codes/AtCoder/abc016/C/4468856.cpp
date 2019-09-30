// Last Change: 03/04/2019 20:00:32.
////////////////////////////////////////////////////////////////////////////
//        ll hoge1, hoge2;
//        hoge1 = min(hoge2, 2LL);  <-???????????ll????
////////////////////////////////////////////////////////////////////////////
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
  ll N, M;
  cin >> N >> M;
  vector<vector<ll>> bridge(N);
  ll iptA, iptB;
  for (ll i = 0; i < M; ++i) {
    cin >> iptA >> iptB;
    --iptA;
    --iptB;
    bridge[iptA].push_back(iptB);
    bridge[iptB].push_back(iptA);
  }

  ll ans;
  for (ll i = 0; i < N; ++i) {
    queue<ll> q;
    vector<ll> people(N, INT64_MAX);
    people[i] = 0;
    ans = 0;
    ll bridgeSize = bridge[i].size();
    for (ll j = 0; j < bridgeSize; ++j) {
      q.push(bridge[i][j]);
      people[bridge[i][j]] = 1;
    }
    while (!q.empty()) {
      ll target = q.front();
      q.pop();
      ll bridgeSizeSize = bridge[target].size();
      for (ll j = 0; j < bridgeSizeSize; ++j) {
        if (people[bridge[target][j]] == INT64_MAX) {
          ++ans;
          people[bridge[target][j]] = 2;
        }
      }
    }
    cout << ans << endl;
  }

  //NS::LoopUntilZeroInpput();
}
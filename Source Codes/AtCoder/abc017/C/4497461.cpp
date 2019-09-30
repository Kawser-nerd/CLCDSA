// Last Change: 03/07/2019 20:44:09.
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

  //?????????
  vector<ll> remain(N + 2);
  //+1???-1???
  vector<vector<pair<ll, int>>> jewely(M + 2);
  ll l, r, all;
  pair<ll, int> tmpPair;
  all = 0;
  for (ll i = 1; i <= N; ++i) {
    cin >> l >> r >> remain[i];
    all += remain[i];

    ++r;
    tmpPair.first = i;
    tmpPair.second = 1;
    jewely[l].push_back(tmpPair);
    tmpPair.second = -1;
    if (r <= M) {
      jewely[r].push_back(tmpPair);
    }
  }

  ll tmpAns, ans;
  ans = 0;
  tmpAns = all;
  for (ll i = 1; i <= M; ++i) {
    ll size = jewely[i].size();
    for (ll j = 0; j < size; ++j) {
      if (jewely[i][j].second > 0) {
        tmpAns -= remain[jewely[i][j].first];
      } else {
        tmpAns += remain[jewely[i][j].first];
      }
    }
    // cout << tmpAns << " ";
    ans = max(ans, tmpAns);
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
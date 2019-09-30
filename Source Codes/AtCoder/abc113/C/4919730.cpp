// Last Change: 04/11/2019 23:33:40.
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

void Mark() {
  static ll index = 0;
  ++index;
  cout << index << " is here!" << endl;
}

int main() {
  ll N, M;
  cin >> N >> M;

  vector<priority_queue<pair<ll, ll>>> pref(N + 1);
  vector<pair<ll, ll>> city(M + 1);

  ll year;
  for (ll i = 0; i < M; ++i) {
    // prefNum, year
    cin >> city[i].first >> year;
    pref[city[i].first].push(make_pair(year, i));
  }

  ll cnt;
  for (ll i = 1; i <= N; ++i) {
    cnt = pref[i].size();
    while (!pref[i].empty()) {
      city[pref[i].top().second].second = cnt;
      pref[i].pop();
      --cnt;
    }
  }

  cout << setfill('0');

  for (ll i = 0; i < M; ++i) {
    cout << setw(6) << city[i].first;
    cout << setw(6) << city[i].second;
    cout << '\n';
  }
  cout << flush;

  //NS::LoopUntilZeroInpput();
}
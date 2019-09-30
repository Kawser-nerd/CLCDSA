// Last Change: 03/14/2019 19:24:38.
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

ll R, C, K;
vector<vector<char>> region;

ll dfs(vector<pair<ll, ll>>& target, ll x, ll cur, ll prev) {
  if (cur >= C) {
    return 0;
  }

  pair<ll, ll> tmp;
  ll hoge = 0;
  if (region[x][cur] == 'o') {
    ++prev;
    hoge = 1;
  } else {
    prev = 0;
  }
  tmp.first = prev;

  tmp.second = dfs(target, x, cur + 1, prev);
  if (hoge == 1) {
    tmp.second += hoge;
  } else {
    tmp.second = 0;
  }

  target[cur] = tmp;

  //????????????????o????????
  return tmp.second;
}

int main() {
  cin >> R >> C >> K;
  region.reserve(R);

  vector<char> ipt(C);
  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      cin >> ipt[j];
    }
    region.push_back(ipt);
  }

  vector<vector<pair<ll, ll>>> regState(R);
  for (int i = 0; i < R; ++i) {
    vector<pair<ll, ll>> tmp(C);
    dfs(tmp, i, 0, 0);
    regState[i] = tmp;
  }

  vector<ll> whatCheck(2 * K - 1);
  int num = 0;
  for (int i = 0; i < 2 * K - 1; ++i) {
    if (i < K) {
      ++num;
    } else {
      --num;
    }
    whatCheck[i] = num;
  }

  ll ans = 0;
  bool state = true;
  for (int x = K - 1; x <= R - K; ++x) {
    for (int y = K - 1; y <= C - K; ++y) {
      state = true;
      for (int i = 0; i < 2 * K - 1; ++i) {
        if (whatCheck[i] > min(regState[x - K + 1 + i][y].first,
                               regState[x - K + 1 + i][y].second)) {
          state = false;
          break;
        }
      }
      if (state) {
        ++ans;
      }
    }
  }
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}
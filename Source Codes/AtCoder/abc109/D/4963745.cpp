// Last Change: 04/14/2019 00:35:49.
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

class Movement {
public:
  int xn, yn, xp, yp;
  Movement(int a, int b, int c, int d) {
    xp = a;
    yp = b;
    xn = c;
    yn = d;
  }
};

int main() {
  int H, W;
  cin >> H >> W;

  vector<vector<ll>> a(H, vector<ll>(W));
  for (int x = 0; x < H; ++x) {
    for (int y = 0; y < W; ++y) {
      cin >> a[x][y];
    }
  }

  vector<Movement> ans;
  queue<pair<int, int>> route;
  for (int x = 0; x < H; ++x) {
    if (x % 2 == 0) {
      for (int y = 0; y < W; ++y) {
        route.push(make_pair(x, y));
      }
    } else {
      for (int y = W - 1; y >= 0; --y) {
        route.push(make_pair(x, y));
      }
    }
  }

  int cal = 0;
  while (route.size() > 1) {
    pair<int, int> cur = route.front();
    route.pop();
    if ((a[cur.first][cur.second] + cal) % 2 == 1) {
      ans.push_back(Movement(cur.first, cur.second, route.front().first,
                             route.front().second));
      cal = 1;
    } else {
      cal = 0;
    }
  }

  cout << ans.size() << endl;
  for (auto &&e : ans) {
    cout << e.xp + 1 << ' ' << e.yp + 1 << ' ' << e.xn + 1 << ' ' << e.yn + 1
         << endl;
  }

  //NS::LoopUntilZeroInpput();
}
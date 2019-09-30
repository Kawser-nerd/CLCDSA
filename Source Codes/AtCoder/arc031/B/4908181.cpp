#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>

// template {{{
using namespace std;

#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define all(x) (x).begin(), (x).end()
#define fill(x, y) memset(x, y, sizeof(x))

using int64 = long long;

int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};

bool in_field(int W, int H, int x, int y) {
  return (0 <= x && x < W) && (0 <= y && y < H);
}

// }}}

// url: https://atcoder.jp/contests/arc031/tasks/arc031_2

typedef pair<int, int> P;

char m[10][10];

int main() {
  rep(i, 10) rep(j, 10) cin >> m[i][j];

  rep(i, 10) rep(j, 10) {
    bool island[10][10];
    bool checked[10][10];
    fill(island, false);
    fill(checked, false);

    island[i][j] = true;

    queue<P> que;
    que.push(P(i, j));
    while (que.size()) {
      P p = que.front();
      que.pop();

      rep(k, 4) {
        int x = p.first + dx[k];
        int y = p.second + dy[k];
        if (!checked[x][y] && m[x][y] == 'o' && in_field(10, 10, x, y)) {
          island[x][y] = true;
          que.push(P(x, y));
          checked[x][y] = true;
        }
      }
    }

    bool all = true;
    rep(x, 10) rep(y, 10) {
      if (m[x][y] == 'o' && !island[x][y])
        all = false;
    }
    if (all) {
      cout << "YES" << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
  return 0;
}

// vim: foldmethod=marker
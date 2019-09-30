#include <cstdio>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <iostream>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 110;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const char *dirs = "v>^<";

int R, C;
char g[MAX][MAX];

inline bool valid(int a, int b) { return a >= 0 && a < R && b >= 0 && b < C; }

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt, fflush(stdout)) {
    scanf("%d%d", &R, &C);
    REP(i, R) scanf("%s", g[i]);
    
    bool ok = true;
    int ans = 0;
    REP(a, R) REP(b, C) if (g[a][b] != '.') {
      bool ima = false;
      bool add = true;
      REP(i, 4) {
        int x = a, y = b;
        x += dx[i];
        y += dy[i];

        while (valid(x, y) && g[x][y] == '.') {
          x += dx[i];
          y += dy[i];
        }

        if (valid(x, y)) {
          ima = true;
          if (dirs[i] == g[a][b]) add = false;
        }
      }

      ok &= ima;
      ans += add;
    }

    printf("Case #%d: ", tt);
    if (!ok) puts("IMPOSSIBLE");
    else printf("%d\n", ans);
  }
  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
using namespace std;

#define all(c) ((c).begin()), ((c).end()) 
#define iter(c) __typeof((c).begin())
#define present(c, e) ((c).find((e)) != (c).end()) 
#define cpresent(c, e) (find(all(c), (e)) != (c).end())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define tr(c, i) for (iter(c) i = (c).begin(); i != (c).end(); ++i)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)

typedef long long ll;

int readint() { 
  int i, j, s;
  while (!isdigit(i = getchar()) && i != '-');
  if (i == '-') { s = -1; j = 0; }
  else { s = 1; j = i - '0'; }
  while (isdigit(i = getchar())) j = ((j << 1) + (j << 3) + (i - '0'));
  return j * s;
}

const int INF = 98765;

struct s_t {
  int x, y, l, r;
  s_t(int a, int b, int c, int d) : x(a), y(b), l(c), r(d) {}
};

int H, W, F;
char fld[110][110];
int cst[110][110][110][110];
char bak[110];

int fail(int x, int y) {
  while (fld[y + 1][x] == '.') y++;
  return y;
}

bool isin(int x, int x1, int x2) {
  return min(x1, x2) <= x && x <= max(x1, x2);
}


int main() {
  int cases = readint();
  rep (ca, cases) {
    H = readint();
    W = readint();
    F = readint();
    for (int y = 1; y <= H; y++) {
      scanf("%s", &fld[y][1]);
      fld[y][0] = fld[y][W + 1] = '#';

      for (int x = 1; x <= W; x++) {
        rep (i, W + 1) rep (j, W + 1) cst[y][x][i][j] = INF;
      }
    }
    for (int x = 0; x <= W + 1; x++) {
      fld[H + 1][x] = '#'; // bottom
    }
    
    multimap<int, s_t> que;
    cst[1][1][0][0] = 0;
    que.insert(mp(0, s_t(1, 1, 0, 0)));

    while (!que.empty()) {
      s_t s = que.begin()->second;
      int c = que.begin()->first;
      que.erase(que.begin());
      int x = s.x, y = s.y, l = s.l, r = s.r;
      if (c > cst[y][x][l][r]) continue;

      // printf("%d %d %d %d\n", x, y, l, r);

      if (y == H) {
        printf("Case #%d: Yes %d\n", ca + 1, c);
        goto done;
      }

      // 地形が変わります！
      for (int tx = 1; tx <= W; tx++) {
        bak[tx] = '.';
        if (isin(tx, x - l, x + r)) swap(fld[y][tx], bak[tx]);
      }

      /*
      for (int y = 1; y <= H + 1; y++) {
        rep (x, W + 2) printf("%c", fld[y][x]);
        puts("");
      }
      puts("");
      */

      // あるく
      for (int dx = -1; dx <= 1; dx += 2) {
        if (fld[y][x + dx] == '#') continue;
        int tx = x + dx;
        int ty = fail(tx, y);
        if (ty - y > F) continue;

        int tl, tr;
        if (ty > y) {
          tl = tr = 0;
        }
        else {
          tl = max(0, l + dx);
          tr = max(0, r - dx);
        }
        // printf(" %d %d %d %d\n", tx, ty, tl, tr);
        int tc = c;
        if (tc < cst[ty][tx][tl][tr]) {
          cst[ty][tx][tl][tr] = tc;
          que.insert(mp(tc, s_t(tx, ty, tl, tr)));
        }
      }

      // 掘ってあるく
      for (int dx = -1; dx <= 1; dx += 2) {
        for (int tn = 1; ; tn++) {
          if (fld[y][x + dx * tn] == '#') break;
          if (fld[y + 1][x + dx * tn] == '.') break;

          // printf(" %d %d -> %d\n", y, x, tn);

          int tx = x + dx;
          int ty = fail(tx, y + 1);
          if (ty - y > F) break;

          int tl, tr;
          if (ty == y + 1) {
            if (dx == -1) tl = tn - 1, tr = 0;
            else tl = 0, tr = tn - 1;
          }
          else {
            tl = tr = 0;
          }
          int tc = c + tn;

          if (tc < cst[ty][tx][tl][tr]) {
            cst[ty][tx][tl][tr] = tc;
            que.insert(mp(tc, s_t(tx, ty, tl, tr)));
          }
        }
      }

      // 地形が戻ります！
      for (int tx = 1; tx <= W; tx++) {
        if (isin(tx, x - l, x + r)) swap(fld[y][tx], bak[tx]);
      }
    }
    printf("Case #%d: No\n", ca + 1);
  done:;
  }
}

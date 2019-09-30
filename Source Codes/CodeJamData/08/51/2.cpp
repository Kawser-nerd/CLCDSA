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

const int INF = 999999999;
const int START = 3500;
 
bool wall1[7000][7000]; // 左手
bool wall2[7000][7000]; // 右手

bool inside[7000][7000];

bool left[7000][7000];
bool right[7000][7000];
bool up[7000][7000];
bool down[7000][7000];

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int minx = INF, miny = INF, maxx = -INF, maxy = -INF;
int inminx[7000], inminy[7000], inmaxx[7000], inmaxy[7000];

int bfs(bool w[7000][7000], int sx, int sy) {
  memset(inside, 0, sizeof(inside));

  if (w[sx][sy]) return 0;

  queue<int> quex, quey;
  quex.push(sx);
  quey.push(sy);
  inside[sx][sy] = true;

  int res = 1;
  while (!quex.empty()) {
    int x = quex.front(); quex.pop();
    int y = quey.front(); quey.pop();

    inminx[y] <?= x; inmaxx[y] >?= x;
    inminy[x] <?= y; inmaxy[x] >?= y;

    rep (i, 4) {
      int tx = x + dx[i];
      int ty = y + dy[i];
      if (w[tx][ty] || inside[tx][ty]) continue;
      quex.push(tx);
      quey.push(ty);
      inside[tx][ty] = true;
      res++;
    }
  }

  return res;
}

int main() {
  int N;
  scanf("%d", &N);
  
  for (int t = 1; t <= N; t++) {
    minx = INF, miny = INF, maxx = -INF, maxy = -INF;

    int x = START, y = START, d = 0;

    memset(wall1, 0, sizeof(wall1));
    memset(wall2, 0, sizeof(wall2));

    int rcnt = 0;
    
    int L;
    scanf("%d", &L);
    rep (i, L) {
      string str;
      int T;
      cin >> str >> T;
      rep (j, T) {
        rep (k, str.length()) {
          switch (str[k]) {
          case 'L':  
            if (x == START && y == START) break; // !!!
            d = (d + 3) % 4;
            rcnt--;
            break;
          case 'R':
            if (x == START && y == START) break; // !!!
            d = (d + 1) % 4;
            rcnt++;
            break;
          case 'F':
            switch (d) {
            case 0:
              wall1[x - 1][y] = true;
              wall2[x][y] = true;
              break;
            case 1:
              wall1[x][y] = true;
              wall2[x][y + 1] = true;
              break;
            case 2:
              wall1[x][y + 1] = true;
              wall2[x - 1][y + 1] = true;
              break;
            case 3:
              wall1[x - 1][y + 1] = true;
              wall2[x - 1][y] = true;
              break;
            }

            x += dx[d];
            y += dy[d];
            
            minx <?= x; maxx >?= x;
            miny <?= y; maxy >?= y;
          }
        }
      }
    }

    while (d != 0) {
      rcnt++;
      d = (d + 1) % 4;
    }

    for (int x = minx - 2; x <= maxx + 2; x++) { inminy[x] = INF; inmaxy[x] = -INF; }
    for (int y = miny - 2; y <= maxy + 2; y++) { inminx[y] = INF; inmaxx[y] = -INF; }


    int hoge;
    if (rcnt > 0) hoge = bfs(wall1, START, START);
    else hoge = bfs(wall2, START - 1, START); // 右回りはnot tested!!!!
    //printf("%d\n", hoge);

    //for (int x = minx - 2; x <= maxx + 2; x++) printf("x%d: %d-%d\n", x, inminy[x], inmaxy[x]);
    //for (int y = miny - 2; y <= maxy + 2; y++) { inminx[y] = INF; inmaxx[y] = -INF; }

    int ans = 0;
    for (int y = miny - 2; y <= maxy + 2; y++) {
      for (int x = minx - 2; x <= maxx + 2; x++) {
        
        if (!inside[x][y] &&
            ((inminx[y] <= x && x <= inmaxx[y]) || (inminy[x] <= y && y <= inmaxy[x])))
          ans++;
      }
    }

    printf("Case #%d: %d\n", t, ans);
  }
}

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
 
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

char fld[30][30];

struct s_t { int x, y, px, py; };

s_t shoot(int x, int y, int pd) {
  int px = x;
  int py = y;
  while (fld[px][py] == '.') {
    px += dx[pd];
    py += dy[pd];
  }
  px -= dx[pd];
  py -= dy[pd];
  //printf("%d %d [%d] %d %d\n", x, y, pd, px, py);
  return (s_t){x, y, px, py};
}

int cst[30][30][30][30];

inline void setcst(const s_t &s, int c) {
  cst[s.x][s.y][s.px][s.py] = c;
}

inline int getcst(const s_t &s) {
  return cst[s.x][s.y][s.px][s.py];
}

int main() {
  int N;
  scanf("%d", &N);

  for (int t = 1; t <= N; t++) {
    printf("Case #%d: ", t);


    int H, W;
    scanf("%d%d", &H, &W);

    memset(fld, '#', sizeof(fld));

    int sx, sy, gx, gy;
    for (int y = 1; y <= H; y++) 
      for (int x = 1; x <= W; x++) {
        scanf(" %c", &fld[x][y]);
        if (fld[x][y] == 'O') { sx = x; sy = y; fld[x][y] = '.'; }
        if (fld[x][y] == 'X') { gx = x; gy = y; fld[x][y] = '.'; }
      }
    
    
    queue<s_t> que;
    memset(cst, -1, sizeof(cst));
    for (int i = 0; i < 4; i++) {
      s_t s = shoot(sx, sy, i);
      que.push(s);
      setcst(s, 0);
    }

    while (!que.empty()) {
      s_t s = que.front();
      int c = getcst(s);
      que.pop();

      if (s.x == gx && s.y == gy) {
        printf("%d\n", getcst(s));
        goto done;
      }

      for (int i = 0; i < 4; i++) {
        int tx = s.x + dx[i];
        int ty = s.y + dy[i];

        if (fld[tx][ty] == '.') {
          for (int j = 0; j <= 4; j++) {
            s_t ts;
            if (j < 4) ts = shoot(tx, ty, j);
            else ts = (s_t){tx, ty, s.px, s.py};
            
            if (getcst(ts) != -1) continue;
            setcst(ts, c + 1);
            que.push(ts);
          }
        }
        else {
          tx = s.px;
          ty = s.py;

          for (int j = 0; j < 4; j++) {
            s_t ts;
            if (j < 4) ts = shoot(tx, ty, j);
            //else ts = (s_t){tx, ty, s.px, s.py};
            
            if (getcst(ts) != -1) continue;
            setcst(ts, c + 1);
            que.push(ts);
          }
        }
      }
    }
    puts("THE CAKE IS A LIE");
    continue;
  done:
    ;
  }
}

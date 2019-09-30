#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int R, C, M, F;
char g[100][100];

int memo[61][61][3001];
bool doit(int y, int r, int cur) {
  int& ret = memo[y][r][cur];
  if (ret != -1) return ret;

  int x;
  if (y == 0) {
    for (x = 0; r && x < C && x < r+1; x++) { g[y][x] = '.'; cur++; }
    for (; x < C; x++) g[y][x] = '*';
  }
  if (y+1 == R) return ret = (cur == F);
  for (x = 0; r && x < C && x < r+1; x++) { g[y+1][x] = '.'; cur++; }
  for (; x < C; x++) g[y+1][x] = '*';
  if (cur > F) return ret = false;
  for (int r2 = 0; r2 <= r; r2++)
    if (doit(y+1, r2, cur)) return ret = true;
  return ret = false;
}

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cin >> R >> C >> M;
    F = R*C-M;
    int r;
    cout << "Case #" << prob++ << ":" << endl;
    memset(memo, -1, sizeof(memo));
    for (r = 1; r <= C; r++) {
      if (doit(0, r, 0)) break;
    }
    if (F == 1) {
      memset(g, '*', sizeof(g));
      g[0][0] = 'c';
      for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) cout << g[y][x];
        cout << endl;
      }
    } else if (r > C) {
      cout << "Impossible" << endl;
    } else {
      g[0][0] = 'c';
      for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) cout << g[y][x];
        cout << endl;
      }
    }
  }
}


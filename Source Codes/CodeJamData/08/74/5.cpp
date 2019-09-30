#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

int R, C;
vector <string> grid;

int convert(int r, int c) {
  return 1<<(C*r+c);
}

int store[65536][4][4];
char seen[65536][4][4];

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int win(int mask, int r, int c) {
  if (seen[mask][r][c]) return store[mask][r][c];
  seen[mask][r][c] = 1;
  int ans = 0;
  for (int k = 0; k < 8; k++) {
    int nr = r + dx[k], nc = c + dy[k];
    if (0 <= nr && nr < R && 0 <= nc && nc < C && !(mask&convert(nr, nc)))
      if (!win(mask|convert(nr, nc), nr, nc)) {
	ans = 1;
	break;
      }
  }
  return store[mask][r][c] = ans;
}

int main(void) {

  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    memset(seen, 0, sizeof(seen));
    cin >> R >> C;
    grid.resize(R);
    int sx = -1, sy = -1, smask = 0;
    for (int r = 0; r < R; r++) {
      cin >> grid[r];
      for (int c = 0; c < C; c++) {
	if (grid[r][c] == 'K') {
	  sx = r; sy = c;
	}
	if (grid[r][c] != '.')
	  smask |= convert(r, c);
      }
    }
    char ans = win(smask, sx, sy) ? 'A' : 'B';
    printf("Case #%d: %c\n", t, ans);
  }
  
}

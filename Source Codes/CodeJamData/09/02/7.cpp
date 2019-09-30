#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cctype>
#include <set>
#include <deque>
#include <queue>
#include <list>
#include <functional>
#include <numeric>
#include <bitset>
#include <ext/hash_set>
#include <ext/hash_map>
#include <stdexcept>
using namespace std;
using namespace __gnu_cxx;

int map[128][128], comp[128][128];
int ly, lx, ncomp;

void dfs(int y, int x) {
  int dy[] = { -1, 0, 0, 1 },
      dx[] = { 0, -1, 1, 0 };
  comp[y][x] = ncomp;

  int nexty, nextx, alt = map[y][x];
  for (int dir = 0; dir < 4; ++dir) {
    int a = y + dy[dir], b = x + dx[dir];
    if (a >= 0 && a < ly && b >= 0 && b < lx && map[a][b] < alt) {
      nexty = a;
      nextx = b;
      alt = map[a][b];
    }
  }
  if (alt < map[y][x]) {
    if (comp[nexty][nextx] < 0)
      dfs(nexty, nextx);
    comp[y][x] = comp[nexty][nextx];
  } else comp[y][x] = ncomp++;
}

int main() {
  int cases;
  scanf("%i\n", &cases);
  for (int caseno = 1; caseno <= cases; ++caseno) {
    printf("Case #%i:\n", caseno);
    scanf("%i%i", &ly, &lx);
    for (int y = 0; y < ly; ++y)
      for (int x = 0; x < lx; ++x) {
        scanf("%i", &map[y][x]);
        comp[y][x] = -1;
      }

    ncomp = 0;
    for (int y = 0; y < ly; ++y)
      for (int x = 0; x < lx; ++x)
        if (comp[y][x] < 0) dfs(y, x);
    for (int y = 0; y < ly; ++y) {
      for (int x = 0; x < lx; ++x) {
        if (x) printf(" ");
        putchar('a' + comp[y][x]);
      }
      puts("");
    }
        

    fflush(stdout);
  }
  return 0;
}

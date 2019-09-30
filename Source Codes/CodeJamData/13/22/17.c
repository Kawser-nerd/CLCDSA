#define DEBUG 0
#define MAXX 10000
#define MAXY 10000

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
using namespace std;

int N, X, Y;
bool g[2 * MAXX + 1][MAXY + 1];
double ans;

void f(int pos, double p, int x, int y, int h) {
  if(DEBUG) printf("pos = %d, p = %.2lf, x = %d, y = %d, h = %d\n", pos, p, x, y, h);
  if(pos == N) {
    if(g[X + MAXX][Y])
      ans += p;
    return;
  }
  if(y == 0) { //ground level
    g[x + MAXX][y] = 1;
    f(pos + 1, p, 0, h, h);
    g[x + MAXX][y] = 0;
    return;
  }
  if(g[x - 1 + MAXX][y - 1] && g[x + 1 + MAXX][y - 1]) { //no where to slide
    g[x + MAXX][y] = 1;
    if(x == 0)
      f(pos + 1, p, 0, h + 2, h + 2);
    else
      f(pos + 1, p, 0, h, h);
    g[x + MAXX][y] = 0;
    return;
  }
  if(g[x - 1 + MAXX][y - 1]) { //must slide right
    f(pos, p, x + 1, y - 1, h);
    return;
  }
  if(g[x + 1 + MAXX][y - 1]) { //must slide left
    f(pos, p, x - 1, y - 1, h);
    return;
  }
  f(pos, p / 2.0, x - 1, y - 1, h);
  f(pos, p / 2.0, x + 1, y - 1, h);
}

int main() {
  int tc, cn;
  scanf("%d", &tc);
  g[MAXX][0] = 1;
  for(cn = 1; cn <= tc; cn++) {
    scanf("%d%d%d", &N, &X, &Y);
    ans = 0.0;
    f(1, 1.0, 0, 2, 2);
    printf("Case #%d: %.7lf\n", cn, ans);
  }
  return 0;
}

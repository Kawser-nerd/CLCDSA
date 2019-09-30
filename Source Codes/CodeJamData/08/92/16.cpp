#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define mp make_pair

int w, h;
int x0, y0, x1, y1, x2, y2;

bool ok( int x, int y )
{
  return 0 <= x && x < w && 0 <= y && y < h;
}

#define m 110

int u[m][m];

void go( int x, int y )
{
  if (!ok(x, y) || u[x][y])
    return;
  u[x][y] = 1;
  go(x + x1, y + y1);
  go(x + x2, y + y2);
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int nt;
  scanf("%d", &nt);
  forn (tt, nt)
  {
    fprintf(stderr, "Case #%d:\n", tt + 1);
    printf("Case #%d: ", tt + 1);

    scanf("%d%d", &w, &h);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    scanf("%d%d", &x0, &y0);
    memset(u, 0, sizeof(u));
//    go(x0, y0);
    int tans = 0;
//    forn (i, w)
//      forn (j, h)
//        tans += u[i][j];

    long long ans = 0;
    if (x1 * y2 == x2 * y1)
    {
      set <pair <int, int> > a, b;
      a.insert(mp(x0, y0));
      b.insert(mp(x0, y0));
      while (a.size() > 0)
      {
        int xx = a.begin()->first;
        int yy = a.begin()->second;
        a.erase(a.begin());
        if (ok(xx + x1, yy + y1) && !b.count(mp(xx + x1, yy + y1)))
        {
          a.insert(mp(xx + x1, yy + y1));
          b.insert(mp(xx + x1, yy + y1));
        }
        if (ok(xx + x2, yy + y2) && !b.count(mp(xx + x2, yy + y2)))
        {
          a.insert(mp(xx + x2, yy + y2));
          b.insert(mp(xx + x2, yy + y2));
        }
      }
      ans = b.size();
    }
    else
    {
      int xs = x0, ys = y0;
      int xf = xs, yf = ys;
      int cur = 1;
      while (true)
      {
        while (ok(xf + x1, yf + y1))
          cur++, xf += x1, yf += y1;
        ans += cur;
        xs += x2, ys += y2;
        xf += x2, yf += y2;
        while (!ok(xs, ys) && (xs != xf || ys != yf))
          cur--, xs += x1, ys += y1;
        while (!ok(xf, yf) && (xs != xf || ys != yf))
          cur--, xf -= x1, yf -= y1;
        if (xf == xs && yf == ys && !ok(xs, ys))
          break;
      }
    }
    printf("%lld", ans);
    fprintf(stderr, "%lld %d\n", ans, tans);
//    if (ans != tans)
//      return 1;

    fprintf(stderr, "Case #%d done\n", tt + 1);
    puts("");
  }
  return 0;
}

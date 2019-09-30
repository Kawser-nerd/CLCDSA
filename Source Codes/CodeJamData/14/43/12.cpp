/**         
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.05.31
 */

#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <bitset>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define zero(a) memset(a, 0, sizeof(a))

const int W = 1000;
const int B = 1000;
const int MAX_Y = 2 * B + 2;
const int H = W * MAX_Y;

int w, h, hh, b;
bitset<W> mark[H];
int yn, y[MAX_Y], new_y[MAX_Y];

int renew( int y0 )
{
  return new_y[lower_bound(y, y + yn, y0) - y];
}

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

inline int good( int x, int y )
{
  return 0 <= x && x < w && 0 <= y && y < hh;
}

inline int go( int x, int y, int k )
{
  if (!good(x, y) || mark[y][x])
    return 0;
  mark[y][x] = 1;
  if (y == hh - 1)
    return 1;

  int kl = (k + 3) & 3;
  int kr = (k + 1) & 3;
  #define F(kl) \
    if (go(x + dx[kl], y + dy[kl], kl)) return 1;
  F(kl)
  F(k)
  F(kr)
  return 0;
}

void solve()
{
  scanf("%d%d%d", &w, &h, &b);

  yn = 0;
  y[yn++] = 0;
  y[yn++] = h;

  int max_w = 0;
  int x0[B], y0[B], x1[B], y1[B];
  forn(i, b)
  {
    scanf("%d%d%d%d", &x0[i], &y0[i], &x1[i], &y1[i]), x1[i]++, y1[i]++;
    y[yn++] = y0[i];
    y[yn++] = y1[i];
    max_w = max(max_w, x1[i] - x0[i]);
  }
  max_w = w - max_w;
  sort(y, y + yn);

  new_y[0] = 0;
  forn(i, yn - 1)
    new_y[i + 1] = new_y[i] + min(max_w, y[i + 1] - y[i]);

  //fprintf(stderr, "!");
  hh = renew(h);
  fprintf(stderr, "[%d->%d]", h, hh);
  assert(hh <= H);
  forn(i, hh)
    mark[i].reset();

  //fprintf(stderr, "!");
  forn(i, b)
  {
    int Y0 = renew(y0[i]);
    int Y1 = renew(y1[i]);
    //fprintf(stderr, "[%d,%d]", Y0, Y1);
    for (int y = Y0; y < Y1; y++)
      for (int x = x0[i]; x < x1[i]; x++)
        mark[y][x] = 1;
  }
  //fprintf(stderr, "!");

  int ans = 0;
  forn(i, w)
    if (!mark[0][i])
      ans += go(i, 0, 1);
  printf("%d\n", ans);
//  return ans;
}

int main()
{
  int tn;
  fprintf(stderr, "run it!\n");
  scanf("%d", &tn);
  forn(t, tn)
  {
    fprintf(stderr, "Case #%d: ", t + 1);
    printf("Case #%d: ", t + 1);
    solve();
    fprintf(stderr, "ok\n");
  }
  return 0;
}

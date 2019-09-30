#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
#define zero(a) memset(a, 0, sizeof(a))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int maxn = 53;
const int inf = (int)1e9;

int h, w, F, f[maxn][maxn][maxn];
char s[maxn][maxn];

int go( int y, int lx, int rx )
{
  int &res = f[y][lx][rx];

  if (res != -1)
    return res;
  res = inf;

//  printf("y=%d lx=%d rx=%d\n", y, lx, rx);

  int cnt = 0, cnt1 = 0, cnt2 = 0;
  for (int i = lx; i <= rx; i++)
    cnt += (s[y][i] == '#');
  for (int i = lx; i <= rx && s[y][i] == '#'; i++)
    cnt1++;
  for (int i = rx; i >= lx && s[y][i] == '#'; i--)
    cnt2++;
  if (cnt1 != cnt && cnt2 != cnt)
    return res;

//  printf(". y=%d lx=%d rx=%d cnt=%d [%d %d]\n", y, lx, rx, cnt, cnt1, cnt2);

  if (lx == 0 && cnt == 0 && y == 0 && (y == h - 1 || s[y + 1][lx] == '#'))
    return res = 0;

  if (lx > 0 && (y == h - 1 || s[y + 1][lx - 1] == '#'))
    res = min(res, go(y, lx - 1, rx));
  if (rx + 1 < w &&  (y == h - 1 || s[y + 1][rx + 1] == '#'))
    res = min(res, go(y, lx, rx + 1));

  if (y > 0)
  {
    if (lx > 0 && cnt1 == cnt && s[y][lx - 1] == '#' && (y == h - 1 || s[y + 1][lx] == '#'))
      res = min(res, go(y - 1, lx - 1, lx - 1 + max(cnt, 1)) + cnt);
    if (rx + 1 < w && cnt2 == cnt && s[y][rx + 1] == '#' && (y == h - 1 || s[y + 1][rx] == '#'))
      res = min(res, go(y - 1, rx + 1 - max(cnt, 1), rx + 1) + cnt);

    if (cnt == 0)
      forn(t, 2)
      {
        int price = 0;
        if (y == h - 1 || s[y + 1][lx] == '#')
          for (int cy = y - 1; cy - 1 >= 0 && cy - 1 >= y - F; cy--)
          {
            price += (s[cy][lx] == '#');
            if (lx > 0 && s[cy][lx - 1] == '#')
              res = min(res, go(cy - 1, lx - 1, lx) + price);
            if (lx + 1 < w && s[cy][lx + 1] == '#')
              res = min(res, go(cy - 1, lx, lx + 1) + price);
            if (price)
              break;
          }
        swap(lx, rx);
      }
  }

//  if (res <= 1)
//    printf("%d [%d,%d] --> %d\n", y, lx, rx, res);
  return res;
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
//    fprintf(stderr, "%d\n", tt);
    scanf("%d%d%d", &h, &w, &F);
    forn(i, h)
      scanf("%s", s[i]);

    printf("Case #%d: ", tt);
/*
    if (tt == 11)
    {
      fprintf(stderr, "%d %d %d\n", h, w, F);
      forn(i, h)
        fprintf(stderr, "%s\n", s[i]);
    }
*/
    
    int res = inf;
    memset(f, -1, sizeof(f));
    forn(i, w)
      res = min(res, go(h - 1, i, i));
    if (res == inf)
      printf("No\n");
    else
      printf("Yes %d\n", res);
  }
  return 0;
}

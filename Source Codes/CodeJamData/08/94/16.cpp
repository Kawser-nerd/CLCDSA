#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define m 33
#define mm (m * m)

int di[4] = {1, 0, -1, 0};
int dj[4] = {0, -1, 0, 1};
char a[m][m];
int u[m][m], uu[m][m], p[m][m], qi[mm], qj[mm], fi, la, w, h;

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

    scanf("%d%d", &h, &w);
    forn (i, h)
      scanf("%s", a[i]);
    forn (i, h)
      forn (j, w)
        u[i][j] = 0;
    u[0][0] = 1;
    int ans = 0;
    while (true)
    {
      fi = la = 0;
      forn (i, h)
        forn (j, w)
          uu[i][j] = -1;
      forn (i, h)
        forn (j, w)
          if (a[i][j] == 'T' && u[i][j])
            qi[la] = i, qj[la++] = j, uu[i][j] = 0;
      while (fi < la)
      {
        int ii = qi[fi], jj = qj[fi++];
        forn (k, 4)
        {
          int ni = ii + di[k], nj = jj + dj[k];
          if (0 <= ni && ni < h && 0 <= nj && nj < w && a[ni][nj] != '.' && uu[ni][nj] == -1)
            qi[la] = ni, qj[la++] = nj, uu[ni][nj] = uu[ii][jj] + 1, p[ni][nj] = k;
        }
      }
      int be = (int)1e9, bi, bj;
      forn (i, h)
        forn (j, w)
          if (!u[i][j] && a[i][j] == 'T' && be > uu[i][j])
            be = uu[i][j], bi = i, bj = j;
      if (be >= (int)1e9)
      {
        forn (i, h)
          forn (j, w)
            if (!u[i][j] && a[i][j] != '.' && be > uu[i][j])
              be = uu[i][j], bi = i, bj = j;
        if (be >= (int)1e9)
          break;
      }
      while (uu[bi][bj] != 0)
      {
        int k = p[bi][bj];
        if (!u[bi][bj])
          ans += uu[bi][bj];
        u[bi][bj] = 1;
        bi -= di[k], bj -= dj[k];
      }
    }
    printf("%d", ans);
    fprintf(stderr, "%d\n", ans);

    fprintf(stderr, "Case #%d done\n", tt + 1);
    puts("");
  }
  return 0;
}

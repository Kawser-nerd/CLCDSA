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

#define m 222

int a[m][m], sum[m][m], nt, r, c;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  scanf("%d", &nt);
  forn (tt, nt)
  {
    fprintf(stderr, "Case #%d:\n", tt + 1);
    printf("Case #%d: ", tt + 1);

    scanf("%d%d", &r, &c);
    forn (i, r)
      forn (j, c)
        scanf("%d", &sum[i + 1][j + 1]);
    int ans = 0;
    forn (i, (1 << (r * c)))
    {
      forn (j, r + 3)
        forn (k, c + 3)
          a[j][k] = 0;
      forn (j, r)
        forn (k, c)
          a[j + 1][k + 1] = (i >> (k * r + j)) & 1;
      bool ok = true;
      forn (j, r)
      {
        forn (k, c)
        {
          int ss = 0;
          for (int jj = j - 1; jj <= j + 1; jj++)
            for (int kk = k - 1; kk <= k + 1; kk++)
              ss += a[jj + 1][kk + 1];
          if (ss != sum[j + 1][k + 1])
            ok = false;
          if (!ok)
            break;
        }
        if (!ok)
          break;
      }
      if (!ok)
        continue;
      fprintf(stderr, "!!");
      int ss = 0;
      forn (j, c)
        ss += a[r / 2 + 1][j + 1];
      ans = max(ans, ss);
    }
    printf("%d", ans);
    fprintf(stderr, "%d\n", ans);

    fprintf(stderr, "Case #%d done\n", tt + 1);
    puts("");
  }
  return 0;
}

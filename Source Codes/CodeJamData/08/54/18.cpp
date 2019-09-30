#include <cstdio>
#include <cstring>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

#define m 111

int nt, h, w, n, c[m][m], r[m][m];

int main()
{
  freopen("knight.in", "r", stdin);
  freopen("knight.out", "w", stdout);
  scanf("%d", &nt);
  forn (tt, nt)
  {
    printf("Case #%d: ", tt + 1);
    scanf("%d%d%d", &h, &w, &n);
    memset(c, 0, sizeof(c));
    forn (i, n)
    {
      int a, b;
      scanf("%d%d", &a, &b), a--, b--;
      c[a][b] = 1;
    }
    forn (i, h)
      forn (j, w)
      {
        r[i][j] = (i == 0 && j == 0);
        if (c[i][j] == 1)
          continue;
        if (i > 1 && j > 0)
          r[i][j] = (r[i - 2][j - 1] + r[i][j]) % 10007;
        if (j > 1 && i > 0)
          r[i][j] = (r[i - 1][j - 2] + r[i][j]) % 10007;
      }
    printf("%d\n", r[h - 1][w - 1]);
  }
  return 0;
}

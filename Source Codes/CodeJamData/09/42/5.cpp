#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <sstream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cmath>

#define eps 1e-9

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define sz(v)((v).size())

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

using namespace std;

#define maxn 55

char s[maxn][maxn];

int n, m, f;

int d[maxn][maxn][maxn][maxn];

void go( int y, int x, int c, int l, int r )
{
  if (y < n - 1 && s[y + 1][x] == '.')
  {
    l = x, r = x;
    int h = 1;
    while (y < n - 1 && s[y + 1][x] == '.')
      h++, y++;
    if (h > f)
      return;
    d[y][x][l][r] <?= c;
  }
  else
  {
    assert(l >= 0 && r >= 0);
    d[y][x][l][r] <?= c;
  }
}

int main( void )
{
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    cerr << tt << "/" << tn << endl;
    printf("Case #%d: ", tt);
    scanf("%d%d%d", &n, &m, &f);

    for (int i = 0; i < n; i++)
      scanf("%s", s[i]);

    memset(d, 63, sizeof(d));
    int inf = d[0][0][0][0];

    d[0][0][0][0] = 0;
    for (int i = 0; i + 1 < n; i++)
      for (int j = 0; j < m; j++)
        for (int _l = 0; _l < m; _l++)
          for (int _r = 0; _r < m; _r++)
            if (d[i][j][_l][_r] != inf)
            {
              int l = j, r = j;
              while (l > 0 && (s[i][l - 1] == '.' || _l <= l - 1 && l - 1 <= _r) && s[i + 1][l - 1] == '#') l--;
              while (r + 1 < m && (s[i][r + 1] == '.' || _l <= r + 1 && r + 1 <= _r) && s[i + 1][r + 1] == '#') r++;

              for (int a = l; a <= r; a++)
                for (int b = a; b <= r; b++)
                {
                  int cost = b - a + d[i][j][_l][_r];
                  if (a < b || a == r && (a + 1 < m && (s[i][a + 1] == '.' || _l <= a + 1 &&  a + 1 <= _r) && s[i + 1][a + 1] == '.'))
                    go(i + 1, a + 1, cost, a + 1, b);

                  if (b > a || b == l && (b - 1 >= 0 && (s[i][b - 1] == '.' || _l <= b - 1 && b - 1 <= _r) && s[i + 1][b - 1] == '.'))
                    go(i + 1, b - 1, cost, a, b - 1);
                }
            }
    int res = inf;
    for (int j = 0; j < m; j++)
      for (int _l = 0; _l < m; _l++)
        for (int _r = 0; _r < m; _r++)
          res <?= d[n - 1][j][_l][_r];
    if (res == inf)
      printf("No\n");
    else
      printf("Yes %d\n", res);
  }

   
  
  return 0;
}
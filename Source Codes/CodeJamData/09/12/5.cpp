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

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldbl;

using namespace std;

#define maxn 22

int was[maxn][maxn][4];

long long d[maxn][maxn][4];
long long _s[maxn][maxn],
          _w[maxn][maxn],
          _t[maxn][maxn];

int main( void )
{
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);
    int h, w;
    scanf("%d%d", &h, &w);

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> _s[i][j] >> _w[i][j] >> _t[i][j];

    memset(was, 0, sizeof(was));
    memset(d, 63, sizeof(d));
    long long inf = d[0][0][0];
    d[h - 1][0][0] = 0;

    while (true)
    {
      int sy = -1, sx = -1, sp = -1;
      for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
          for (int k = 0; k < 4; k++)
            if (d[i][j][k] != inf && (sy == -1 || d[sy][sx][sp] > d[i][j][k]) && !was[i][j][k])
              sy = i, sx = j, sp = k;
      if (sy == -1)
        break;

      was[sy][sx][sp] = 1;
//      fprintf(stderr, "%d %d %d\n", sy, sx, sp);

      long long st = d[sy][sx][sp], mod = (_s[sy][sx] + _w[sy][sx]), diff = ((st - _t[sy][sx]) % mod + mod) % mod, 
                d1, d2;
      if (diff < _s[sy][sx])
        d1 = 0, d2 = _s[sy][sx] - diff;
      else
        d2 = 0, d1 = mod - diff;
      if (sp == 0)
      {
        if (sx > 0)
          d[sy][sx - 1][1] <?= st + 2;
        if (sy + 1 < h)
          d[sy + 1][sx][2] <?= st + 2;
        d[sy][sx][2] <?= st + d1 + 1;
        d[sy][sx][1] <?= st + d2 + 1;
      }
      if (sp == 1)
      {
        if (sx + 1 < w)
          d[sy][sx + 1][0] <?= st + 2;
        if (sy + 1 < h)
          d[sy + 1][sx][3] <?= st + 2;
        d[sy][sx][3] <?= st + d1 + 1;
        d[sy][sx][0] <?= st + d2 + 1;
      }
      if (sp == 2)
      {
        if (sx > 0)
          d[sy][sx - 1][3] <?= st + 2;
        if (sy > 0)
          d[sy - 1][sx][0] <?= st + 2;
        d[sy][sx][0] <?= st + d1 + 1;
        d[sy][sx][3] <?= st + d2 + 1;
      }
      if (sp == 3)
      {
        if (sx + 1 < w)
          d[sy][sx + 1][2] <?= st + 2;
        if (sy > 0)
          d[sy - 1][sx][1] <?= st + 2;
        d[sy][sx][1] <?= st + d1 + 1;
        d[sy][sx][2] <?= st + d2 + 1;
      }
    }

    cout << d[0][w - 1][3] << endl;
  }

   
  
  return 0;
}
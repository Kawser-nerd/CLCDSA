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

ldbl _c[55][55], f[110];

int main( void )
{
  _c[0][0] = 1;
  for (int i = 0; i < 50; i++)
    for (int j = 0; j <= i; j++)
      _c[i + 1][j] += _c[i][j],
      _c[i + 1][j + 1] += _c[i][j];
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);

    int c, n;
    scanf("%d%d", &c, &n);

    memset(f, 0, sizeof(f));
    for (int i = c - 1; i >= 0; i--)
    {
      double tmp = 0, my = 1;
      for (int x = 0; x <= n && x <= i; x++)
      {
        double v =  _c[i][x] * _c[c - i][n - x] / _c[c][n];
        if (x == n)
          my -= v;
        else
          tmp += v * f[i + n - x];
      }
      f[i] = (tmp + 1) / my;
    }

    printf("%.20lf\n", (double)f[0]);
  }

   
  
  return 0;
}
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

#define maxn 110

vector <int> a[maxn];

int g[maxn][maxn], py[maxn], was[maxn];

int n, k;

bool dfs( int v )
{
  was[v] = 1;
  for (int i = 0; i < n; i++)
    if (g[v][i] && (py[i] == -1 || !was[py[i]] && dfs(py[i])))
    {
      py[i] = v;
      return true;
    }
  return false;
}

int main( void )
{
  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    printf("Case #%d: ", tt);

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
      a[i] = vector <int> (k);
      for (int j = 0; j < k; j++)
        scanf("%d", &a[i][j]);
    }

    memset(g, 0, sizeof(g));
    memset(was, 0, sizeof(was));
    memset(py, -1, sizeof(py));

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
      {
        g[i][j] = 1;
        for (int t = 0; t < k; t++)
          g[i][j] &= a[i][t] > a[j][t];
      }

    int res = n;
    for (int i = 0; i < n; i++)
    {
      memset(was, 0, sizeof(was));
      if (dfs(i))
        res--;
    }
    
    printf("%d\n", res);

  }

   
  
  return 0;
}
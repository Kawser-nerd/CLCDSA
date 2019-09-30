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

const int maxn = 103;

int n, k, a[maxn][maxn], c[maxn][maxn];
int cc, u[maxn], pa[maxn];

int dfs( int v )
{
  u[v] = 1;
  forn(i, n)
    if (c[v][i] && (pa[i] == -1 || (!u[pa[i]] && dfs(pa[i]))))
    {
      pa[i] = v;
      return 1;
    }
  return 0;
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    scanf("%d%d", &n, &k);
    forn(i, n)
      forn(j, k)
        scanf("%d", &a[i][j]);
    forn(i, n)
      forn(j, n)
      {
        int bad = 0;
        forn(t, k)
          if (a[i][t] >= a[j][t])
            bad = 1;
        c[i][j] = !bad;
      }    
/*
    forn(i, n)
      forn(j, n)
        printf("%d%c", c[i][j], " \n"[j == n - 1]);
*/

    memset(pa, -1, sizeof(pa));
    cc = 0;
    forn(i, n)
    {
      memset(u, 0, sizeof(u));
      if (dfs(i))
        cc++;
    }
//    forn(i, n)
//      printf("pa[%d] = %d\n", i, pa[i]);

    printf("Case #%d: %d\n", tt, n - cc);
  }
  return 0;
}

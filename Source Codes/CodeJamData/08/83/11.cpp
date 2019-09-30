#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

typedef vector <int> vi;
typedef long long ll;
typedef double dbl;
typedef pair <int, int> pii;
typedef vector <string> vs;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forit(i, a) for (__typeof((a).begin() i = (a).begin(); i != (a).end(); i++)

#define pb push_back

#define MOD 1000000009

#define m 555

int n, k;
vi c[m];

int dfs( int v, int p, int pp, int nbr )
{
  int ch = (int)c[v].size() - (p != -1);
  int t = k - nbr - (p != -1) - (pp != -1);
  if (t < ch)
    return 0;
  int ans = 1;
  forn (i, ch)
    ans = (int)(((ll)ans * (ll)(t - i)) % MOD);
//  fprintf(stderr, "v=%d p=%d pp=%d ans=%d\n", v, p, pp, ans);
  forn (i, c[v].size())
    if (c[v][i] != p)
      ans = (int)(((ll)ans * (ll)dfs(c[v][i], v, p, ch - 1)) % MOD);
  return ans;
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  int nt;
  scanf("%d", &nt);
  forn (tn, nt)
  {
    printf("Case #%d: ", tn + 1);
    scanf("%d%d", &n, &k);
    forn (i, n - 1)
    {
      int a, b;
      scanf("%d%d", &a, &b);
      a--, b--;
      c[a].pb(b);
      c[b].pb(a);
    }
    int ans = dfs(0, -1, -1, 0);
    printf("%d", ans);
    forn (i, n)
      c[i].clear();
    puts("");
  }
  return 0;
}


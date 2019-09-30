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

const int maxn = 1010;
const int maxy = 32;

int n, x[maxn], y[maxn];
int last[maxy];
vector <int> c[maxn];
int bad, en, u[maxn];

void AddE( int a, int b )
{
  en++;
  c[a].pb(b), c[b].pb(a);
}

void dfs( int v, int col )
{
  u[v] = col;
  forn(i, sz(c[v]))
  {
    int x = c[v][i];
    if (!u[x])
      dfs(x, 3 - col);
    else if (u[x] == col)
      bad = 1;
  }
}

int P = 239017;
set <ll> m;

int go( int i, int LX, int LY, int LC )
{
  if (i == n)
    return 1;

  ll hash = i;
  hash = hash * P + LX;
  hash = hash * P + LY;
  hash = hash * P + LC;
  forn(j, maxy)
    hash = hash * P + last[j];
  if (m.count(hash))
    return 0;
  m.insert(hash);

  int is[4];
  memset(is, 0, sizeof(is));
  for (int j = y[i] - 1; j <= y[i] + 1; j++)
  {
    if (LX == x[i] && LY == j)
      is[LC] = 1;
    else
      is[last[j]] = 1;
  }

  int &ref = last[y[i]];
  forn(col, 3)
    if (!is[col])
    {
      int tmp = ref;
      ref = col;
      if (go(i + 1, x[i], y[i], tmp))
        return 1;
      ref = tmp;
    }

  return 0;
}

int Solve()
{
  forn(i, maxy)
    last[i] = 3;
  m.clear();
  return go(0, -3, -3, 3);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    scanf("%d", &n);
    fprintf(stderr, "%d n=%d\n", tt, n);
    forn(i, n)
      scanf("%d%d", &x[i], &y[i]);
    forn(i, n)
      forn(j, n - 1)
        if (mp(x[j + 1], y[j + 1]) > mp(x[j], y[j]))
        {
          swap(x[j], x[j + 1]);
          swap(y[j], y[j + 1]);
        }
    memset(last, -1, sizeof(last));
    forn(i, n)
      c[i].clear();
    en = 0;
    forn(i, n)
    {
      for (int j = y[i] - 1; j <= y[i] + 1; j++)
        if (last[j] != -1)
          AddE(i, last[j]);
      last[y[i]] = i;
    }    

    int ans = -1;
    if (en == 0)
      ans = 1;
    else
    {
      memset(u, 0, sizeof(u));
      bad = 0;
      forn(i, n)
        if (!u[i])
          dfs(i, 1);
      if (!bad)
        ans = 2;
      else if (Solve())
        ans = 3;
      else
        ans = 4;
    }
    
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

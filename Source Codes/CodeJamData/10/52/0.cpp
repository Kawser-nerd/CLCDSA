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

const int maxr = (int)1e6 + 10;

ll L;
int n, b[maxr];
int qst, qen, q[maxr * 2], u[maxr], d[maxr];

void AddQ( int v, int x, int dx )
{
  assert(qst > 0 && qen + 1 < 2 * maxr);
  if (!u[v] || d[v] > x)
  {
    u[v] = 1, d[v] = x;
    if (!dx)
      q[--qst] = v;
    else
      q[qen++] = v;
  }
}

int main()
{
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);
    scanf("%I64d%d", &L, &n);
   
    int ma = 0;
    forn(i, n)
      scanf("%d", &b[i]), ma = max(ma, b[i]);

    ll ans = (L + ma - 1) / ma;
    int rest = ans * ma - L;

    qst = qen = maxr;
    memset(u, 0, sizeof(u));
    AddQ(rest, 0, 1);
    while (qst < qen)
    {
      int v = q[qst++];
      forn(i, n)
      {
        int dif = ma - b[i];
        if (dif <= v)
          AddQ(v - dif, d[v], 0);
        else
          AddQ(v - dif + ma, d[v] + 1, 1);
      }
    }

    printf("Case #%d: ", tt);
    if (!u[0])
      puts("IMPOSSIBLE");
    else
      printf("%I64d\n", ans + d[0]);
  }
  return 0;
}

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

#define MOD 1000000007
#define maxn (int)2e7

ll L, R;

int an = 0;
ll a[maxn], deg[100];

void go( int i, int len, ll x, ll y )
{
  if (2 * i >= len)
  {        
    if (len & 1)
      a[an++] = (x - x % 10) * deg[len / 2] + y;
    else
      a[an++] = x * deg[len / 2] + y;
    return;
  }
  for (int d = (i == 0); d <= 9; d++)
    go(i + 1, len, x * 10 + d, y + deg[i] * d);
}

int main()
{
  const int M = 13;

  deg[0] = 1;
  for (int len = 1; len <= M; len++)
    deg[len] = deg[len - 1] * 10;

  a[an++] = 0;
  for (int len = 1; len <= M; len++)
  {
    go(0, len, 0, 0);
    fprintf(stderr, "len=%d an=%d\n", len, an);
  }
  a[an++] = deg[M] + 1;
  
  int tn;
  scanf("%d", &tn);
  for (int tt = 1; tt <= tn; tt++)
  {
    fprintf(stderr, "%d\n", tt);

    ll L, R;
    scanf("%I64d%I64d", &L, &R);

    ll sum[2] = {0, 0};
    for (int i = 0; i < an - 1; i++)
    {
      sum[i & 1] += max(0LL, min(a[i + 1], R + 1) - a[i]);
      if (a[i] > R + 1)
        break;
    }

    ll ans = 0;

    for (int i = 0; i < an - 1; i++)
    {
      sum[i & 1] -= max(0LL, min(a[i + 1], R + 1) - a[i]);

      ll len = max(0LL, min(R + 1, a[i + 1] + 1) - max(a[i] + 1, L));

      if (a[i] > R + 1)
        break;

      if (len == 0)
        continue;

      ans += sum[i & 1] * len;
      len = max(0LL, min(R + 1, a[i + 1]) - max(a[i] + 1, L));
      ans += len * (len + 1) / 2;
      ans %= MOD;
    }

    printf("Case #%d: ", tt);
    printf("%I64d\n", ans);
  }
  return 0;
}

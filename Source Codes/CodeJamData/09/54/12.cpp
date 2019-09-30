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
#include <ext/hash_map>
#include <ext/hash_set>

#define eps 1e-9

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define forit(i, s) for(__typeof(s.begin()) i = s.begin(); i != s.end(); i++)
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

using namespace __gnu_cxx;

namespace __gnu_cxx
{
template<> struct hash<long long>
{ size_t operator()(long long __x) const { return (size_t)(__x * __x); } };
}
#define maxn 20000010

ll all[maxn];
ll dl[maxn][2], dr[maxn][2];

ll f1( ll x )
{
  char s[10];
  sprintf(s, "%I64d", x);
  int n = strlen(s);

  ll res = 0;
  for (int i = 0; i < n; i++)
    res = res * 10 + s[i] - '0';
  for (int i = n - 1; i >= 0; i--)
    res = res * 10 + s[i] - '0';
  return res;
}

ll f2( ll x )
{
  char s[10];
  sprintf(s, "%I64d", x);
  int n = strlen(s);

  ll res = 0;
  for (int i = 0; i < n; i++)
    res = res * 10 + s[i] - '0';
  for (int i = n - 2; i >= 0; i--)
    res = res * 10 + s[i] - '0';
  return res;
}

ll mod = 1000000007ll;

ll _f( ll x )
{
  x %= mod;
  return ((x * (x + 1)) / 2) % mod;
}

int main( void )
{
  int n = 0;
  for (int i = 1; i <= 9999999; i++)
  {
    if (i <= 999999)
      all[n++] = f1(i);
    all[n++] = f2(i);
  }
  sort(all, all + n);

  cerr << n << endl;

  int tn;
  scanf("%d", &tn);

  for (int tt = 1; tt <= tn; tt++)
  {
    cerr << tt << endl;
    printf("Case #%d: ", tt);
    ll l, r;
    cin >> l >> r;

    vector <int> toCh;

    int f = 1;

    ll res = 0;

    for (int i = 0; i < n; i++)
      if (l <= all[i] && all[i] <= r)
      {
        if (f)
        {
          dl[i][0] = all[i] - l + 1, dl[i][1] = 0, f = 0;
          res = (res + _f(all[i] - l)) % mod;
        }
        else
        {
          dl[i][0] = all[i] - all[i - 1] + dl[i - 1][1], dl[i][1] = dl[i - 1][0];
          res = (res + _f(all[i] - all[i - 1] - 1)) % mod;
        }
      }
    f = 1;
    for (int i = n - 1; i >= 0; i--)
      if (l <= all[i] && all[i] <= r)
      {

        if (f)
        {
          dr[i][0] = r - all[i] + 1, dr[i][1] = 0, f = 0;
          res = (res + _f(r - all[i])) % mod;
        }
        else
        {
          dr[i][0] = all[i + 1] - all[i], dr[i][1] = 0;
        }

        res = (res + dl[i][0] * dr[i][1]) % mod;
        res = (res + dl[i][1] * dr[i][0]) % mod;
      }
    if (f)
      res = (_f(r - l + 1)) % mod;
    cout << res << endl;
  }

  


  return 0;
}
#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it=(a).begin(); it!=(a).end(); ++it)

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

const int maxn = 105;

vector<ll> a;
set<pii> h;
int n;
ll l, r;

ll gcd(ll x, ll y)
{
  return y ? gcd(y, x%y) : x;
}

ll res;
void func(int i, ll gc, ll lc)
{

  if (gc != 0 && gc % lc != 0) return;
  if (lc > r || (gc != 0 && gc < l)) return;
  if (lc > res) return;
  if (i >= n)
  {
    if (h.find(mp(gc, lc)) != h.end()) return;
    if (sz(h) < 100000) h.insert(mp(gc, lc));
//    printf("func: %d %lld %lld\n", i, gc, lc);
    ll q = gc/lc;
    ll need = (l+lc-1)/lc;
    if (q == 0)
    {
      if (need*lc >= l && need*lc <= r) res = min(res, need*lc);
      return;
    }
  //  printf("need = %lld\n", need);
    for (ll x=1; x*x<=q; ++x) if (q%x==0)
    {
      if (x*lc >=l && x*lc <= r)
      {
        res = min(res, x*lc);
        return;
      }
      ll y = q/x;
      if (y*lc >= l && y*lc <= r)
        res = min(res, y*lc);
    }    
    return;
  }
  
  func(i+1, gcd(gc, a[i]), lc);
  ll gg = gcd(lc, a[i]);
  ll q = lc/gg;
  if (q <= r/a[i])
    func(i+1, gc, q*a[i]);  
}

ll solve()
{
  if (l == 1) return 1;
  if (n == 0) return l;
  reverse(a.begin(), a.end());
//  foreach (it, a) printf("%lld ", *it); puts("");
  res = r+1;
  func(0, 0, 1);  
  return res == r+1 ? -1 : res;
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  int tc; scanf("%d", &tc);
  for (int tt=1; tt<=tc; ++tt)
  {
    h.clear();
    fprintf(stderr, "Test Case %d:\n", tt);
    cin >> n >> l >> r;
    a.clear();
    forn (i, n)
    {
      ll x; cin >> x;
      if (x == 0 || x == 1) continue;
      a.pb(x);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());
    n = sz(a);
    ll res = solve();
    printf("Case #%d: ", tt);
    if (res == -1) puts("NO");
    else printf("%lld\n", res);
  }
  
  return 0;
}

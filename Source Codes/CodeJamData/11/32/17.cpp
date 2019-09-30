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
typedef pair<int,int> pii;

const int maxn = 2000005;
const ll inf = 1LL<<61;

ll a[maxn];
int n, k;
ll t;

ll solve(vector<int> a, int k)
{
  ll res = 0;
//  foreach (it, a) printf("%d ", *it); puts("");
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  forn (i, sz(a))
  {
    if (i < k) res += a[i];
    else res += 2*a[i];
  }
  //cout << res << endl;  
  return res; 
}

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  int tc; scanf("%d", &tc);
  for (int tt=1; tt<=tc; ++tt)
  {
    int c;
    cin >> k >> t >> n >> c;
    forn (i, c) cin >> a[i];
    forn (i, n) a[i] = a[i%c];
    
    ll res = 0;
    forn (i, n) res += 2*a[i];
    ll sum = 0, fr = n;
    forn (i, n)
    {
      if (sum+2*a[i] >= t) { fr = i; break; }
      sum += 2*a[i];
    }
    vector<int> b;
    for (int i=fr+1; i<n; ++i) b.pb(a[i]);
    if (k > 0)
    {     
      ll cur = sum;
      ll q = t-sum;
      cur += a[fr]-q/2+q;
      res = min(res, cur+solve(b, k-1));
    }
    res = min(res, sum+2*a[fr]+solve(b, k));   
    
    
    
    
    printf("Case #%d: %lld\n", tt, res);
  }
  
  return 0;
}

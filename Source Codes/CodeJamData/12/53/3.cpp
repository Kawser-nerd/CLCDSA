#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 204;

pair<ll, ll> a[MAXN];
ll m, f;
int n;

pair<ll, ll> getAns(ll p){
  int i;
  ll t = m-f*p;
  ll d = 0;
  ll ans = 0;
  for(i = 0; i < n; i++){
    if(a[i].se>d){
      if(t/a[i].fi/p >= a[i].se-d){
        ans += (a[i].se-d)*p;
        t -= a[i].fi*(a[i].se-d)*p;
        d = a[i].se;
      }
      else{
        ans += t/a[i].fi;
        t %= a[i].fi;
        return mp(ans, t);
      }
    }
  }
  return mp(ans, t);
}

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  for(int i0 = 1; i0 <= T; i0++){
    printf("Case #%d: ", i0);
    int i, j;
    ll l, r;
    cin>>m>>f>>n;
    for(i = 0; i < n; i++){
      cin>>a[i].fi>>a[i].se;
      a[i].se++;
    }
    sort(a, a+n);
    l = 1;
    r = m/f;
    while(l < r){
      ll mid = (l+r)/2;
      pair<ll, ll> t1 = getAns(mid), t2 = getAns(mid+1);
      if(t1 == t2){
        l = mid;
        break;
      }
      if(t1 < t2){
        l = mid+1;
      }
      else{
        r = mid;
      }
    }
    cout<<getAns(l).fi<<endl;
  }
  return 0;
}

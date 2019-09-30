#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FORE(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
typedef long long ll;

const int N=11000;
int _,n;
ll l,h,a[N],ans,minans;

ll mnoz(ll a, ll b) {
   if ( double(a) * double(b) > 10*h) return h+1;
   a *= b;
   if (a > h) return h+1;
   return a;
}

vector<ll> divs(ll a) {
   static map<ll,vector<ll> > m;
   if (m.find(a)!=m.end()) return m[a];
   vector<ll> r;
   for(ll i=1;i*i<=a;++i)
      if (a % i==0) r.push_back(i), r.push_back(a/i);
   sort(r.begin(),r.end());
   return m[a]=r;
}

int main() {
   scanf("%d",&_);
   REP(test,_) {
      printf("Case #%d: ",test+1);
      scanf("%d%lld%lld",&n,&l,&h);
      REP(i,n) scanf("%lld",&a[i]);
      sort(a,a+n);
      ans = 1;
      minans = h+1;
      for(int i=-1;i<n;++i) {
	 if (i>=0) ans = mnoz(ans, (a[i] / __gcd(ans,a[i])));

	 ll g = -1;
	 if (i+1 < n) {
	    g = a[i+1];
	    for(int j=i+1;j<n;++j) g = __gcd(g,a[j]);
	 }
	 ll tans = ans;
	 if (g!=-1 && g % tans) continue;
	 if (tans > h) continue;
	 else if (tans < l) {
	    int ok=0;
//	    for(int k=(l+tans-1)/tans; k*tans <= h; ++k)
//	       if (g==-1 || g % (k*tans) == 0) { ok=1; tans = k*tans; break; }
	    if (g==-1) {
	       int k = (l+tans-1)/tans;
	       if (k*tans <= h) { ok=1; tans=k*tans; }
	    }
	    else {
	       vector<ll> D = divs(g / tans);
	       FORE(i,D) if (l <= tans**i && tans**i <= h) { ok=1; tans = *i*tans; break; }
	    }
	    if (!ok) continue;
	 }
	 if (tans < minans) minans = tans;
      }
ret:
      if (minans > h) puts("NO");
      else printf("%lld\n",minans);
      fflush(stdout);
   }
}

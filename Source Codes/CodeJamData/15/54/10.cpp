#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=11000;
pair<ll,ll> p[N],q[N];
map<ll,ll> f,g;
int _,__,n;
vector<ll> ret;
int Log(ll x) {
	int s=0;
	while (x>1) x/=2,s++;
	return s;
}
int main() {
//	freopen("in.txt","r",stdin);
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,n) scanf("%I64d",&p[i].fi);
		rep(i,0,n) scanf("%I64d",&p[i].se);
		sort(p,p+n);
		ll C=p[0].fi;
		rep(i,0,n) p[i].fi-=C;
		ret.clear();
		ll d=p[0].se;
		int r=Log(d);
		rep(i,0,r) ret.pb(0);
		rep(i,0,n) {
			assert(p[i].se%d==0);
			p[i].se/=d;
		}
		rep(i,0,n) q[i]=p[i];
		int tot=n;
		while (tot>1) {
			ret.pb(p[1].fi);
			ll s=p[1].fi;
			f.clear(); g.clear();
			rep(i,0,tot) g[p[i].fi]=p[i].se;
			per(i,0,tot) {
				f[p[i].fi]=g[p[i].fi+s]-f[p[i].fi+s];
			}
			tot=0;
			for (auto it:f) {
				assert(it.se>=0);
				if (it.se>0) p[tot++]=mp(it.fi,it.se);
			}
		}
		sort(all(ret)); reverse(all(ret));
		tot=n; C*=-1;
		rep(i,0,SZ(ret)) {
			ll s=ret[i];
			if (s==0) continue;
			f.clear(); g.clear();
			rep(i,0,tot) g[q[i].fi]=q[i].se;
			per(i,0,tot) {
				f[q[i].fi]=g[q[i].fi+s]-f[q[i].fi+s];
			}
			tot=0;
			for (auto it:f) {
				assert(it.se>=0);
				if (it.se>0) q[tot++]=mp(it.fi,it.se);
			}
			if (f[C-ret[i]]) {
				C-=ret[i];
				ret[i]*=-1;
			}
		}
		assert(C==0);
		printf("Case #%d:",++__);
		sort(all(ret));
		for (auto p:ret) printf(" %I64d",p);
		puts("");
	}
}

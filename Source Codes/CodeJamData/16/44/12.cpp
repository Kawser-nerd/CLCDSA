#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

VI e[60];
int g[40][40],vis[60],T,c0,c1,n,_,__;
char a[60];
int dp[10100000];
ll st[50];
PII val[50];
int key[50],res[50],m;
map<PII,int> v;
void dfs(int u) {
	vis[u]=T;
	if (u<n) c0++; else c1++;
	for (auto v:e[u]) if (vis[v]==-1) dfs(v);
}
bool check1(int S) {
	rep(i,0,2*n) e[i].clear();
	rep(i,0,n) rep(j,0,n) if ((S>>(i*n+j))&1) {
		e[i].pb(j+n); e[j+n].pb(i);
		g[i][j]=1;
	} else g[i][j]=0;
	rep(i,0,2*n) vis[i]=-1;
	T=0;
	rep(i,0,2*n) if (vis[i]==-1) {
		c0=0,c1=0;
		dfs(i);
		T++;
		if (c0!=c1) return 0;
	}
	rep(i,0,n) rep(j,0,n) if ((vis[i]==vis[j+n])!=g[i][j]) return 0;
	return 1;
}
void dfs(int d,int c0,int c1,int T,int S) {
	if (d==m) {
		if (c0==c1) dp[S]=min(dp[S],dp[S-T]+c0*c0);
	}
	else rep(j,0,res[d]+1) dfs(d+1,c0+j*val[d].fi,c1+j*val[d].se,T+j*st[d],S);

}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d",&n);
		rep(i,0,2*n) e[i].clear();
		int eg=0;
		rep(i,0,n) {
			scanf("%s",a);
			rep(j,0,n) if (a[j]=='1') {
				g[i][j]=1; eg++;
				e[i].pb(j+n); e[j+n].pb(i);
			}
		}
		int ret=n*n+1;
		rep(i,0,2*n) vis[i]=-1;
		T=0;
		v.clear();
		rep(i,0,2*n) if (vis[i]==-1) {
			c0=0,c1=0;
			dfs(i);
			T++;
			v[mp(c0,c1)]++;
//			v.pb(mp(c0,c1));
		}
//		sort(all(v));
		m=0; st[0]=1;
		for (auto p:v) {
			val[m]=p.fi;
			key[m]=p.se;
			st[m+1]=st[m]*(key[m]+1);
			++m;
		}
		fprintf(stderr,"%lld\n",st[m]);
		dp[0]=0;
		rep(i,1,st[m]) {
			dp[i]=10000;
			rep(j,0,m) res[j]=i/st[j]%(key[j]+1);
			dfs(0,0,0,0,i);
//			printf("%d : %d\n",i,dp[i]);
//			puts("");
		}
//		dfs(0,0);
		printf("Case #%d: %d\n",++__,dp[st[m]-1]-eg);
	}
}

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

const int N=1010000;
VI son[N];
int _,n,d,fs[N*2],__;
ll s[N],as,cs,rs,m[N],am,cm,rm;
void dfs(int u,int ms,int rs) {
	ms=min(ms,(int)s[u]); rs=max(rs,(int)s[u]);
	if (rs<=ms+d) fs[rs]++,fs[ms+d+1]--;
	for (auto v:son[u]) {
		dfs(v,ms,rs);
	}
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&d);
		scanf("%I64d%I64d%I64d%I64d",s,&as,&cs,&rs);
		scanf("%I64d%I64d%I64d%I64d",m,&am,&cm,&rm);
		rep(i,0,n) son[i].clear();
		memset(fs,0,sizeof(fs));
		rep(i,0,n-1) {
			s[i+1]=(s[i]*as+cs)%rs;
			m[i+1]=(m[i]*am+cm)%rm;
		}
		rep(i,1,n) son[m[i]%i].pb(i);
		dfs(0,s[0],s[0]);
		int cs=0,ans=0;
		rep(i,0,rs+d+100) {
			cs+=fs[i];
			ans=max(ans,cs);
		}
		printf("Case #%d: %d\n",++__,ans);
	}
}

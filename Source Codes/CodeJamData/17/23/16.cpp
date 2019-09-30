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

const int N=110;
int _,n,q,e[N],s[N],u,v,__;
ll g[N][N];
double dis[N][N];
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&n,&q);
		rep(i,0,n) scanf("%d%d",e+i,s+i);
		rep(i,0,n) rep(j,0,n) {
			scanf("%lld",&g[i][j]);
			if (g[i][j]==-1) g[i][j]=(ll)(1e18);
		}
		rep(i,0,n) g[i][i]=0;
		rep(k,0,n) rep(i,0,n) rep(j,0,n) g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
		rep(i,0,n) rep(j,0,n) if (g[i][j]<=e[i]) dis[i][j]=1.*g[i][j]/s[i]; else dis[i][j]=1e18;
		rep(k,0,n) rep(i,0,n) rep(j,0,n) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		printf("Case #%d:",++__);
		rep(i,0,q) {
			scanf("%d%d",&u,&v); --u; --v;
			printf(" %.10f",dis[u][v]);
		}
		puts("");
	}
}

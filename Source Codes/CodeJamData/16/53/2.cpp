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

const int N=1010;
int _,__;
int n,s,x[N],y[N],z[N],f[N];
int find(int x) { return f[x]==x?x:f[x]=find(f[x]); }
vector<pair<double,PII> > e;
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		scanf("%d%d",&n,&s);
		rep(i,0,n) f[i]=i;
		rep(i,0,n) {
			scanf("%d%d%d%*d%*d%*d",x+i,y+i,z+i);
		}
		e.clear();
		rep(i,0,n) rep(j,i+1,n) {
			e.pb(mp(sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])),mp(i,j)));
		}
		sort(all(e));
		for (auto p:e) {
			int u=p.se.fi,v=p.se.se;
			f[find(u)]=find(v);
			if (find(0)==find(1)) {
				printf("%.10f\n",p.fi);
				break;
			}
		}
	}
}

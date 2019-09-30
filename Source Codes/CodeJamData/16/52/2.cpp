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

int _,__;
string ret[501000];
char s[110],l[110];
int n,m,f;
VI e[110];
void merge(string &a,string b) {
	string c;
	int p=SZ(a),q=SZ(b);
	while (p+q!=0) {
		int r=rand()%(p+q);
		if (r<p) c.pb(a[SZ(a)-p]),--p;
		else c.pb(b[SZ(b)-q]),--q;
	}
	a=c;
}
string sample(int u) {
	string c="";
	for (auto v:e[u]) {
		merge(c,sample(v));
	}
	if (u!=0) c=s[u]+c;
	return c;
}
int main() {
	for (scanf("%d",&_);_;_--) {
		printf("Case #%d: ",++__);
		fprintf(stderr,"Case #%d:\n",__);
		scanf("%d",&n);
		rep(i,0,n+1) e[i].clear();
		rep(i,1,n+1) {
			scanf("%d",&f);
			e[f].pb(i);
		}
		scanf("%s",s+1);
		rep(i,0,10000) {
			ret[i]=sample(0);
//			printf("%d %s\n",i,ret[i].c_str());
		}
		scanf("%d",&m);
		rep(i,0,m) {
			scanf("%s",l);
			int c=0;
			rep(j,0,10000) {
				if (ret[j].find(l)!=ret[j].npos) c++;
			}
			printf("%.10f ",c/10000.);
		}
		puts("");
	}
}

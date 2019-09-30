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

const int N=410;
int _,R,C,u,v,__;
int p[N],f[N],r[N][N],c[N][N],pos[N];
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%d",&R,&C);
		rep(i,0,R+C) {
			scanf("%d%d",&u,&v);
			p[u]=v; p[v]=u;
		}
		bool sol=0;
		printf("Case #%d:\n",++__);
		rep(S,0,(1<<(R*C))) {
			int m=0;
			rep(i,0,R+1) rep(j,0,C) r[i][j]=m++;
			rep(i,0,R) rep(j,0,C+1) c[i][j]=m++;
			rep(i,0,C) pos[i+1]=r[0][i];
			rep(i,0,R) pos[i+C+1]=c[i][C];
			per(i,0,C) pos[R+C+C-i]=r[R][i];
			per(i,0,R) pos[R+C+C+R-i]=c[i][0];
			rep(i,0,m) f[i]=i;
			rep(i,0,R) rep(j,0,C) {
				if ((S>>(i*C+j))&1) {
//					printf("%d %d\n",r[i][j],c[i][j]);
//					printf("%d %d\n",r[i+1][j],c[i][j+1]);
					f[find(r[i][j])]=find(c[i][j]);
					f[find(r[i+1][j])]=find(c[i][j+1]);
				} else {
//					printf("%d %d\n",r[i][j],c[i][j+1]);
//					printf("%d %d\n",r[i+1][j],c[i][j]);
					f[find(r[i][j])]=find(c[i][j+1]);
					f[find(r[i+1][j])]=find(c[i][j]);					
				}
			}
			bool val=1;
			rep(i,1,2*(R+C)+1) {
				if (find(pos[i])!=find(pos[p[i]])) { val=0; break;}
			}
			if (val) {
				rep(i,0,R) {
					rep(j,0,C) {
						if ((S>>(i*C+j))&1) putchar('/'); else putchar('\\');
					}
					puts("");
				}
				sol=1;
				break;
			}
		}
		if (!sol) puts("IMPOSSIBLE");
	}
}

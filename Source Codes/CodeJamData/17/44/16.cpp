#include<stdio.h>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<utility>
#include<functional>
#include<iomanip>
#include<sstream>
#include<ctime>
#include<cassert>
using namespace std;
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define fil(a,b) memset((a),(b),sizeof(a))
#define cl(a) fil(a,0)
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define foreach(it,a) for(__typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define rep(i,a,b) for (int i=(a),_ed=(b);i<_ed;i++)
#define per(i,a,b) for (int i=(b)-1,_ed=(a);i>=_ed;i--)
#define forg(i,gu) for (int i=gu;~i;i=e[i].next)
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
void getre(){int x=0;printf("%d\n",1/x);}
void gettle(){int res=1;while(1)res<<=1;printf("%d\n",res);}
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
template<typename T,typename S>inline bool upmin(T&a,const S&b){return a>b?a=b,1:0;}
template<typename T,typename S>inline bool upmax(T&a,const S&b){return a<b?a=b,1:0;}
template<typename N,typename PN>inline N flo(N a,PN b){return a>=0?a/b:-((-a-1)/b)-1;}
template<typename N,typename PN>inline N cei(N a,PN b){return a>0?(a-1)/b+1:-(-a/b);}
template<typename N>N gcd(N a,N b){return b?gcd(b,a%b):a;}
template<typename N>inline int sgn(N a){return a>0?1:(a<0?-1:0);}
#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
#define lld "%I64d"
#else
#define lld "%lld"
#endif
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
#ifdef JCVB
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...)
#endif
typedef long long ll;
typedef double db;
inline ll sqr(ll a){return a*a;}
inline db sqrf(db a){return a*a;}
const int inf=0x3f3f3f3f;
//const ll inf=0x3f3f3f3f3f3f3f3fll;
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

char s[111][111];
int n,m,lim;
vpii ren,ta;

bool f[1<<10][1<<10];
pii pre[1<<10][1<<10];

int dis[111][111];
inline bool ok(int i,int j){
	return i>=1 && i<=n && j>=1 && j<=m && s[i][j]!='#';
}
pii qu[111*111];
int notleave[111][111];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool test(int siren,int sita,int idren,int idta){
	rep(i,1,n+1)rep(j,1,m+1){
		dis[i][j]=inf;
		notleave[i][j]=0;
	}
	rep(i,0,ta.size())if(!(pw(i)&sita)){
		rep(d,0,4){
			int x=ta[i].fi,y=ta[i].se;
			while(ok(x,y)){
				notleave[x][y]=1;
				if(i==idta)notleave[x][y]|=2;
				x+=dx[d];
				y+=dy[d];
			}
		}
	}
	dis[ren[idren].fi][ren[idren].se]=0;
	int p=0,q=0;
	qu[q++]=ren[idren];
	while(p!=q){
		pii u=qu[p++];
		int x=u.fi,y=u.se;
		if(dis[x][y]>lim)break;
		if((notleave[x][y]&2))return 1;
		if(notleave[x][y])continue;
		rep(d,0,4)if(ok(x+dx[d],y+dy[d])){
			if(upmin(dis[x+dx[d]][y+dy[d]],dis[x][y]+1)){
				qu[q++]=mp(x+dx[d],y+dy[d]);
			}
		}
	}
	return 0;
}
void dfs(int a,int b){
	if(a==0  && b==0)return;
	pii mm=pre[a][b];
	dfs(a^pw(mm.fi),b^pw(mm.se));
	printf("%d %d\n",mm.fi+1,mm.se+1);
}
void main_work(){ //remember to clear all variables
	ren.clear();ta.clear();
	gn(m);gn(n);gn(lim);
	rep(i,1,n+1)gs(s[i]+1);

	rep(i,1,n+1)rep(j,1,m+1){
		if(s[i][j]=='S')ren.pb(mp(i,j));
		if(s[i][j]=='T')ta.pb(mp(i,j));
	}
	rep(i,0,pw(siz(ren)))
		rep(j,0,pw(siz(ta)))f[i][j]=0;

	f[0][0]=1;

	rep(i,0,pw(siz(ren)))rep(j,0,pw(siz(ta)))if(f[i][j]){
		rep(k,0,siz(ren))if(!(pw(k)&i))
			rep(l,0,siz(ta))if(!(pw(l)&j)){
				if(test(i,j,k,l)){
					f[i|pw(k)][j|pw(l)]=1;
					pre[i|pw(k)][j|pw(l)]=mp(k,l);
				}
			}
	}

	int ma=0;
	pii jue=mp(0,0);
	rep(i,0,pw(siz(ren)))rep(j,0,pw(siz(ta)))if(f[i][j]){
		if(upmax(ma,buli(j))){
			jue=mp(i,j);
		}
	}
	printf("%d\n",ma);
	dfs(jue.fi,jue.se);
}
int main()
{
#ifdef JCVB
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	int _time_jc=clock();
#endif
	int tes;gn(tes);
	rep(_,1,tes+1){
		printf("Case #%d: ",_);
		//printf("Case #%d:\n",_);
		main_work();
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}



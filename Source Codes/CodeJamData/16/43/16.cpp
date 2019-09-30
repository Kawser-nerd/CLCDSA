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
const db pi=3.14159265358979323846264338327950288L;
const db eps=1e-6;
//const int mo=0;
//int qp(int a,ll b){int n=1;do{if(b&1)n=1ll*n*a%mo;a=1ll*a*a%mo;}while(b>>=1);return n;}

int r,c;
char s[550][550];
int to[511];

int fa[555];
int gf(int x){return x==fa[x]?x:fa[x]=gf(fa[x]);}
void un(int x,int y){
	fa[gf(x)]=gf(y);
}
int id[555];
bool check(){
	int tot=r*(c+1)+(r+1)*c;
	rep(i,1,tot+1)fa[i]=i;
	rep(i,1,r+1)rep(j,1,c+1){
		int up=(i-1)*c+j,dow=i*c+j;
		int le=(r+1)*c+(i-1)*(c+1)+j,
			ri=(r+1)*c+(i-1)*(c+1)+j+1;
		if(s[i][j]=='/'){
			un(up,le);un(dow,ri);
		}else{
			un(up,ri);un(dow,le);
		}
	}
	rep(i,1,c+1){
		id[i]=i;
	}
	rep(i,1,r+1){
		id[c+i]=(r+1)*c+(i)*(c+1);
	}
	rep(i,1,c+1){
		id[c+r+c-i+1]=r*c+i;
	}
	rep(i,1,r+1){
		id[c+r+c+r-i+1]=(r+1)*c+(i-1)*(c+1)+1;
	}
	rep(i,1,2*r+2*c+1)if(gf(id[i])!=gf(id[to[i]]))return 0;
	rep(i,1,r+1){
		rep(j,1,c+1)putchar(s[i][j]);
		putchar('\n');
	}
	return 1;
}
bool dfs(int x,int y){
	if(x==r+1){
		if(check())return 1;
	}else if(y==c+1){
		if(dfs(x+1,1))return 1;
	}else{
		s[x][y]='/';
		if(dfs(x,y+1))return 1;
		s[x][y]='\\';
		if(dfs(x,y+1))return 1;
	}
	return 0;
}
void work(){
	gn(r);gn(c);
	rep(i,1,r+c+1){
		int x,y;gn(x);gn(y);
		to[x]=y;to[y]=x;
	}
	if(dfs(1,1));
	else{
		printf("IMPOSSIBLE\n");
	}
}
int main()
{
#ifdef JCVB
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int _time_jc=clock();
#endif
	int tes;gn(tes);
	rep(_,1,tes+1){
		printf("Case #%d:\n",_);
		work();
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}



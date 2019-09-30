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

int n;
char kai[111];
int fa[111];
char seq[111];
vi chd[111];
string an;

int per[111];
int pos[111];

int getmi(int rt){
	int mi=pos[rt];
	rep(i,0,siz(chd[rt]))upmin(mi,getmi(chd[rt][i]));
	return mi;
}
void dfs(int rt){
	int x=getmi(rt);
	int y=pos[rt];
	swap(pos[rt],pos[per[x]]);
	swap(per[x],per[y]);
	rep(i,0,siz(chd[rt]))dfs(chd[rt][i]);
}
string gen(int rt){
	rep(i,0,n+1)per[i]=i;
	random_shuffle(per,per+n+1);
	rep(i,0,n+1)pos[per[i]]=i;

	dfs(rt);
	string res="";
	rep(i,0,n+1)res+=kai[per[i]];
	return res;
}
db calc(){
	if(strlen(seq+1)>n)return 0.0;
	int le=strlen(seq+1);
	int tot=10000;
	int su=0;
	rep(_,0,tot){
		an=gen(0);
		int boo=0;
		for (int i=1;i<=n-le+1;i++){
			int bo=1;
			for  (int j=1;j<=le;j++)if(seq[j]!=an[i+j-1]){
				bo=0;
				break;
			}
			if(bo==1){
				boo=1;
				break;
			}
		}
		su+=boo;
	}
	return 1.0*su/tot;
}
void work(){
	gn(n);
	rep(i,1,n+1)gn(fa[i]);
	rep(i,0,n+1)chd[i].clear();
	rep(i,1,n+1)chd[fa[i]].pb(i);
	gs(kai+1);
	int m;
	gn(m);
	while(m--){
		gs(seq+1);
		printf("%.6lf ",calc());
	}
	printf("\n");
}
int main()
{
#ifdef JCVB
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	int _time_jc=clock();
#endif
	int tes;gn(tes);
	rep(_,1,tes+1){
		printf("Case #%d: ",_);
		work();
	}
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}



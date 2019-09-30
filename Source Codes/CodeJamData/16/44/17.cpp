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
char s[33][33];
int ad=0;
int mi;
int fa[66];
int cna[66],cnb[66];
int gf(int x){
	return x==fa[x]?x:fa[x]=gf(fa[x]);
}
void un(int x,int y){
	fa[gf(x)]=gf(y);
}
pii lis[30];int to;
int lefa,lefb;
int bian;
void add(int l,int r){
	if(l==0 && r==1)lefb++;
	else if(l==1 && r==0)lefa++;
	else if(l==1 && r==1)bian++;
	else lis[to++]=mp(l,r);
}
int f[1<<16][26][26];
int posi[1<<16];
int iniposi[1<<16],inia[1<<16],inib[1<<16];
void work(){
	mi=inf;
	gn(n);
	rep(i,1,n+1)gs(s[i]+1);
	rep(i,1,n+1)rep(j,1,n+1)s[i][j]-='0';
	rep(i,1,2*n+1)fa[i]=i,cna[i]=0,cnb[i]=0;
	int alr=0;
	rep(i,1,n+1)rep(j,1,n+1)if(s[i][j]){
		un(i,j+n);
		alr++;
	}
	rep(i,1,n+1)cna[gf(i)]++;
	rep(i,1,n+1)cnb[gf(i+n)]++;
	to=0;
	lefa=lefb=0;
	bian=0;
	rep(i,1,n+1){
		if(gf(i)==i)add(cna[i],cnb[i]);
		if(gf(i+n)==i+n)add(cna[i+n],cnb[i+n]);
	}
	assert(to<=16);

	rep(i,0,pw(to)){
		posi[i]=iniposi[i]=inia[i]=inib[i]=0;
		rep(j,0,n+1)rep(k,0,n+1)f[i][j][k]=inf;
	}
	rep(i,0,pw(to)){
		int sua=0,sub=0;
		rep(j,0,to)if(pw(j)&i)sua+=lis[j].fi,sub+=lis[j].se;
		if(sua<=sub){
			int ned=sub-sua;
			if(ned<=lefa)f[i][ned][0]=sub*sub,posi[i]=iniposi[i]=1,inia[i]=ned;
		}else{
			int ned=sua-sub;
			if(ned<=lefb)f[i][0][ned]=sua*sua,posi[i]=iniposi[i]=1,inib[i]=ned;
		}
	}
	rep(i,0,pw(to)){
		for (int j=(i-1)&i;j;j=(j-1)&i){
			int k=i^j;
			if(!posi[k] || !iniposi[j])continue;
			rep(aa,0,lefa+1)rep(bb,0,lefb+1)if(f[k][aa][bb]<inf && aa+inia[j]<=lefa && bb+inib[j]<=lefb){
				upmin(f[i][aa+inia[j]][bb+inib[j]],f[k][aa][bb]+f[j][inia[j]][inib[j]]);
				posi[i]=1;
			}
		}
	}
	int mas=pw(to)-1;
	rep(aa,0,lefa+1)rep(bb,0,lefb+1)if(f[mas][aa][bb]<inf){
		assert(lefa-aa==lefb-bb);
		upmin(mi,f[mas][aa][bb]+(lefa-aa));
	}

	printf("%d\n",mi+bian-alr);
}
int main()
{
#ifdef JCVB
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
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



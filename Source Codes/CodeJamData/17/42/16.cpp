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

const int E=1000000;
const int V=1000000;
const int infc=inf;
const int inff=inf;
namespace COST{
int s,t,vtot;
struct edge{int v,ne;ll f,c;}e[E*2];int g[V],et;
void ae(int u,int v,ll f,ll c){
	e[et]={v,g[u],f,c}; g[u]=et++;
	e[et]={u,g[v],0,-c};g[v]=et++;
}
int to[V];
ll d[V];
bool spfa(){
	static int qu[V],in[V];
	int p=0,q=0;
	qu[q++]=s;in[s]=1;
	rep(i,1,vtot+1) d[i]=infc;
	d[s]=0;
	while(p!=q){
		int u=qu[p++]; if(p==V)p=0;
		in[u]=0;
		for (int i=g[u];~i;i=e[i].ne){
			int v=e[i].v;
			if(e[i].f && d[v]>d[u]+e[i].c){
				d[v]=d[u]+e[i].c;
				to[v]=i;
				if(!in[v]){
					in[v]=1;
					qu[q++]=v; if(q==V)q=0;
				}
			}
		}
	}
	return d[t]<infc;
}
ll flo;
ll mcmf(){
	ll co=0;
	flo=0;
	while(spfa()){
		// if(d[t]>0)break;
		ll f=inff;
		for (int u=t;u!=s;u=e[to[u]^1].v) 
			f=min(f,e[to[u]].f);
		flo+=f;
		co+=f*d[t];
		for (int u=t;u!=s;u=e[to[u]^1].v) 
			e[to[u]].f-=f, e[to[u]^1].f+=f;
	}
	return co;
}
void init(){
	rep(i,1,vtot+1)g[i]=-1;
	et=0;
}

};


int n_seat,n_person,n_ticket;

int deg_per[2222];
int tmp[2222];
void main_work(){ //remember to clear all variables
	gn(n_seat);
	gn(n_person);
	gn(n_ticket);
	cl(deg_per);
	cl(tmp);
	using namespace COST;
	rep(i,1,n_ticket+1){
		int pos,person;
		gn(pos);gn(person);
		tmp[pos]++;
		deg_per[person]++;
	}
	int madeg=0;
	rep(i,1,n_person+1)upmax(madeg,deg_per[i]);


	for (int te=madeg;;te++){
		s=n_seat*2+1;
		t=s+1;
		vtot=t;
		init();

		rep(i,1,n_seat){
			ae(i+n_seat+1,i+n_seat,inf,0);
		}
		rep(i,1,n_seat+1){
			ae(i,i+n_seat,inf,1);
			ae(i+n_seat,i,inf,0);
		}
		rep(i,1,n_seat+1){
			ae(s,i,tmp[i],0);
			ae(i,t,te,0);
		}
		ll co=mcmf();
		if(COST::flo==n_ticket){
			printf("%d "lld"\n",te,co);
			break;
		}
	}
}
int main()
{
#ifdef JCVB
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
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



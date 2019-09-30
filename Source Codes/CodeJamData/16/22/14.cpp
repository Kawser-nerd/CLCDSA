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


char sc[22],sj[22];
char cc[22],cj[22];
char anc[22],anj[22];
ll dif;ll nuc,nuj;
int d;

void updat(){
	ll c=0,j=0;
	rep(i,0,d){
		c=c*10+cc[i]-'0';
		j=j*10+cj[i]-'0';
	}
	ll di=abs(c-j);
	if(di<dif){
		dif=di;
		rep(i,0,d)anc[i]=cc[i],anj[i]=cj[i];
		nuc=c;nuj=j;
	}else if(di==dif){
		if(c<nuc || (c==nuc && j<nuj)){
			dif=di;
			rep(i,0,d)anc[i]=cc[i],anj[i]=cj[i];
			nuc=c;nuj=j;
		}
	}
}
		
void work(int id){
	rep(i,0,id)if(sc[i]!='?' && sj[i]!='?' && sc[i]!=sj[i])return;
	if(id<d && sc[id]!='?' && sj[id]!='?' && sc[id]==sj[id])return;


	rep(nc,0,10)rep(nj,0,10){

		if(nc==nj)continue;
		rep(i,0,d)cc[i]=sc[i],cj[i]=sj[i];
		if(id!=d){
			if(cc[id]!='?' && cc[id]!=nc+'0')continue;
			if(cj[id]!='?' && cj[id]!=nj+'0')continue;
			cc[id]=nc+'0';
			cj[id]=nj+'0';
		}
		rep(i,0,id)
			if(cc[i]=='?' && cj[i]=='?')cc[i]=cj[i]='0';
			else if(cc[i]!='?')cj[i]=cc[i];
			else if(cj[i]!='?')cc[i]=cj[i];
		cc[id]=nc+'0';
		cj[id]=nj+'0';
		if(nc>nj){
			rep(i,id+1,d)if(cc[i]=='?')cc[i]='0';
			rep(i,id+1,d)if(cj[i]=='?')cj[i]='9';
		}else{
			rep(i,id+1,d)if(cc[i]=='?')cc[i]='9';
			rep(i,id+1,d)if(cj[i]=='?')cj[i]='0';
		}
		updat();
	}
}
int main()
{
#ifdef JCVB
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int _time_jc=clock();
#endif
	int tes;gn(tes);
	rep(_,1,tes+1){
		printf("Case #%d: ",_);
		gs(sc);
		gs(sj);
		d=strlen(sc);
		//reverse(sc,sc+d);
		//reverse(sj,sj+d);
		dif=5e18;
		rep(i,0,d+1)work(i);
		rep(i,0,d)putchar(anc[i]);
		putchar(' ');
		rep(i,0,d)putchar(anj[i]);
		putchar('\n');
	}

	
#ifdef JCVB
	debug("time: %d\n",int(clock()-_time_jc));
#endif
	return 0;
}


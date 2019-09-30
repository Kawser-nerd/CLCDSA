/*
Date: 2016/08/05 12:15:03 Friday
Author: 
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define eps 1e-8
#define pi 3.1415926535897
#define sqr(x) ((x)*(x))
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)
#define SZ(x) ((int)(x).size())
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define POSIN(x,y) (1<=(x)&&(x)<=n&&1<=(y)&&(y)<=m)
#define all(x) (x).begin(),(x).end()
#define COUT(S,x) cout<<fixed<<setprecision(x)<<S<<endl
#define buli(x) (__builtin_popcountll(x))
#define bur0(x) (__builtin_ctzll(x))
#define bul2(x) (63-__builtin_clzll(x))
#define pw(x) ((ll(1))<<(x))
#define upmo(a,b) (((a)=((a)+(b))%mo)<0?(a)+=mo:(a))
#define mmo(a,b) (((a)=1ll*(a)*(b)%mo)<0?(a)+=mo:(a))
#define y0 y0z
#define y1 y1z
#define yn ynz
#define j0 j0z
#define j1 j1z
#define jn jnz
#define tm tmz
#ifdef LOCAL
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) 
#endif
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x3f3f3f3f;
const int mo=1000000007;
inline void gn(long long&x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
inline void gn(double&x){double t;scanf("%lf",&t);x=t;}
inline void gn(long double&x){double t;scanf("%lf",&t);x=t;}
template<class T>inline void gn(T&a,T&b){gn(a);gn(b);}
template<class T>inline void gn(T&a,T&b,T&c){gn(a);gn(b);gn(c);}
template<class T>inline void gn(T&a,T&b,T&c,T&d){gn(a);gn(b);gn(c);}
inline void gs(char *s){scanf("%s",s);}
inline void gc(char &c){while((c=getchar())>126 || c<33);}
inline void pc(char c){putchar(c);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mo;for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}
ll powmod(ll a,ll b,ll mo) {ll res=1;a%=mo;for(;b;b>>=1){if(b&1)res=res*a%mo;a=a*a%mo;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=10011,M=111111;
int l,m,n,t,C;
int a[N][N],b[N][N],c[N][N];
int inv[N];
int main(){
#ifdef LOCAL
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
#endif
	n=10000;
	rep(i,1,n)inv[i]=powmod(i,mo-2);
	rep(i,2,n){
		rep(j,1,i){
			if(j==2||j==i-1)a[i][j]=1;
			else if(j!=1&&j!=i)a[i][j]=1ll*(2+b[i-2][j]+c[i-2][j-2])*inv[i-1]%mo;
			else if(j==1)a[i][j]=1ll*(1+b[i-2][j])*inv[i-1]%mo;
			else if(j==i)a[i][j]=1ll*(1+c[i-2][j-2])*inv[i-1]%mo;
			b[i][j]=(a[i][j]+b[i-1][j])%mo;
			c[i][j]=(a[i][j]+c[i-1][j-1])%mo;
		}
	}
	gn(C);rep(_,1,C){
		printf("Case #%d: ",_);
		gn(n,m);printf("%d\n",a[n][m]);
	}
	return 0;
}

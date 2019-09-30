/*
Date: 2016/06/11 21:54:46 Saturday
Author: xllend3
*/
#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define ph push
#define pb push_back
#define REP(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define DEP(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define rep(i,a,n) for(int i=(a);i<=(n);++i)
#define dep(i,a,n) for(int i=(a);i>=(n);--i)
#define ALL(x,S) for(__typeof((S).end()) x=S.begin();x!=S.end();x++)
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
typedef long long ll;
typedef double lf;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<lf,lf> pff;
typedef complex<double> CD;
const int inf=0x20202020;
const int mod=1000000007;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
template<class T> inline void read(T&x,T&y,T&z,T&q){read(x);read(y);read(z);read(q);}
const int DX[]={1,0,-1,0},DY[]={0,1,0,-1};
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
//*******************************************

const int N=111111,M=111111;
int l,m,n,t,C;
char s[N],q[N],p[N];
int f[N];
vector<int>a[N];
lf jc[N];
struct zcc{int sz;lf p;}dp[N];
lf RAN(){return 1.0*rand()/RAND_MAX;}
void add(zcc &a,zcc b){
	if(a.sz==0){a=b;return;}
	a.p*=jc[a.sz+b.sz]/jc[a.sz]/jc[b.sz]*b.p;a.sz+=b.sz;
}
void del(zcc &a,zcc b){
	a.sz-=b.sz;a.p/=jc[a.sz+b.sz]/jc[a.sz]/jc[b.sz]*b.p;
}
zcc tmp[N];
vector<int>Q;
void gen(){
	zcc t={0,0};
	for(auto i:a[0])add(t,dp[i]),Q.pb(i);
	rep(i,1,n){
		lf sum=0;int pos=*(Q.begin());
		for(auto i:Q){
			tmp[i]=t;del(tmp[i],dp[i]);for(auto j:a[i])add(tmp[i],dp[j]);sum+=tmp[i].p;
		}
		sum*=RAN();
		for(auto i:Q){
			sum-=tmp[i].p;if(sum<=0){pos=i;break;}
		}
		int w=0;while(Q[w]!=pos)++w;rep(i,w,SZ(Q)-1)Q[i]=Q[i+1];Q.pop_back();
		for(auto j:a[pos])Q.pb(j);
		p[i]=s[pos];t=tmp[pos];
	}
}
lf work(){
	int sum=0,nn=10000;
	rep(_,1,nn){
		gen();
		//p[n+1]=0;printf("%s\n",p+1);
		rep(i,0,n-l){
			int bo=1;rep(j,1,l)if(p[i+j]!=q[j])bo=0;if(bo){++sum;break;}
		}
	}return 1.0*sum/nn;
}
void DP(int x){
	dp[x]={0,0};
	for(auto i:a[x])DP(i),add(dp[x],dp[i]);
	dp[x].sz++;if(dp[x].sz==1)dp[x].p=1;
}
int main(){
	//ios::sync_with_stdio(false);
#ifdef LOCAL
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
#endif
	jc[0]=1;rep(i,1,1000)jc[i]=jc[i-1]*i;
	read(C);rep(_,1,C){
		printf("Case #%d: ",_);
		fprintf(stderr,"%d\n",_);
		read(n);
		rep(i,0,n)a[i].clear();
		rep(i,1,n)read(f[i]),a[f[i]].pb(i);
		DP(0);
		scanf("%s",s+1);
		read(m);rep(_,1,m){
			scanf("%s",q+1);l=strlen(q+1);printf("%.5lf",work());putchar(_==m?'\n':' ');
		}
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

ll dp[200010][2];
ll pre[200010];
int main(){
	rep(i,0,200005)pre[i]=-1;
	ll n;
	scanf("%lld",&n);
	ll t;
	scanf("%lld",&t);
	pre[t]=0;
	dp[0][1]=1;
	rep(i,1,n){
		ll t;
		scanf("%lld",&t);
		dp[i][1]=(dp[i-1][0]+dp[i-1][1])%MOD;
		if(pre[t]!=-1&&pre[t]!=i-1)dp[i][0]=(dp[pre[t]][0]+dp[pre[t]][1])%MOD;
		pre[t]=i;
//		printf("%lld %lld\n",dp[i][0],dp[i][1]);
	}
	printf("%lld",(dp[n-1][0]+dp[n-1][1])%MOD);
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&t);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^
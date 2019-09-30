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

ll n,k;
ll s[50];
ll dp[50][2];
int main(){
	scanf("%lld%lld",&n,&k);
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		rep(j,0,50)if(bit(t,j))s[j]++;
	}
	for(int j=45;j>=0;j--){
		if(bit(k,j)){
			dp[j][0]=dp[j+1][0]+((n-s[j])<<j);
			if(dp[j+1][1]==0)dp[j][1]=dp[j+1][0]+(s[j]<<j);
			else dp[j][1]=max(max(dp[j+1][1]+(s[j]<<j),dp[j+1][1]+((n-s[j])<<j)),dp[j+1][0]+(s[j]<<j));
		}else{
			dp[j][0]=dp[j+1][0]+(s[j]<<j);
			if(dp[j+1][1]==0)dp[j][1]=0;
			else dp[j][1]=max(dp[j+1][1]+(s[j]<<j),dp[j+1][1]+((n-s[j])<<j));
		}
	}
	printf("%lld\n",max(dp[0][0],dp[0][1]));
} ./Main.c: In function ‘main’:
./Main.c:24:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^
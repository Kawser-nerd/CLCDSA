#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n,t;
ll dp[100010];
int main(){
	scanf("%lld\n",&n);
	dp[0]=1;
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		for(ll j=10000;j>=0;j--)dp[j+t]+=dp[j];
	}
	for(ll j=10000;j>=0;j--)if(j%10&&dp[j]){
		printf("%lld\n",j);
		return 0;
	}
	puts("0");
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld\n",&n);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^
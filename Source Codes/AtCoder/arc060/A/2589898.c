#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n,m;
ll temp[10000],*dp=temp+3000;
ll a[99];
int main(){
	scanf("%lld%lld",&n,&m);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)a[i]-=m;
	dp[0]=1;
	rep(i,0,n){
		if(a[i]<=0)rep(j,-2800,2800)dp[j+a[i]]+=dp[j];
		else for(ll j=2800;j>-280;j--)dp[j+a[i]]+=dp[j];
	}
	printf("%lld\n",dp[0]-1);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&m);
  ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^
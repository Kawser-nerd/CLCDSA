#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll ans;
ll n;
ll a[100010];
ll b[100010];
int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld%lld",a+i,b+i);
	for(ll i=n-1;i>=0;i--)if((a[i]+ans)%b[i])ans+=b[i]-(a[i]+ans)%b[i];
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:16:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld%lld",a+i,b+i);
            ^
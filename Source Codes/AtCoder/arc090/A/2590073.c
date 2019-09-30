#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll a[110];
ll b[110];
ll ans;
int main(){
	ll n;
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n)scanf("%lld",b+i);
	rep(k,0,n){
		ll s=0;
		rep(i,0,k+1)s+=a[i];
		rep(i,k,n)s+=b[i];
		ans=max(ans,s);
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:16:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^
./Main.c:17:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",b+i);
            ^
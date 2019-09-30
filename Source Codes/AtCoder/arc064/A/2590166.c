#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll n,x;
ll a[100010];
ll ans;
int main(){
	scanf("%lld%lld",&n,&x);
	rep(i,0,n)scanf("%lld\n",a+i);
	rep(i,1,n){
		if(a[i-1]+a[i]>=x){
			ans+=a[i-1]+a[i]-x;
			a[i]=max(0,x-a[i-1]);
		}
	}
	printf("%lld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&x);
  ^
./Main.c:15:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld\n",a+i);
            ^
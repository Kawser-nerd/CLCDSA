#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))



ll n,k;
ll a[100010];
int main(){
	scanf("%lld%lld",&n,&k);
	rep(i,0,n){
		ll p,q;
		scanf("%lld%lld",&p,&q);
		a[p]+=q;
	}
	ll cnt=0;
	rep(i,1,100010){
		cnt+=a[i];
		if(cnt>=k){
			printf("%lld\n",i);
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&p,&q);
   ^
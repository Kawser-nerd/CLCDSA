#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll a,b,c,d,n;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&n);
	c=min(a*4,min(b*2,c));
	ll ans=0;
	if(2*c>d){
		ans+=n/2*d;
		n%=2;
	}
	printf("%lld\n",ans+n*c);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&n);
  ^
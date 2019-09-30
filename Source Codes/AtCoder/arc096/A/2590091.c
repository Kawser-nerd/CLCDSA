#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))


int main(){
	ll a,b,c,x,y;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
	ll ans=0;
	if(2*c<=a+b){
		ll d=min(x,y);
		ans+=c*2*d;
		x-=d;
		y-=d;
	}
	if(2*c<=a){
		ans+=c*2*x;
		x=0;
	}
	if(2*c<=b){
		ans+=c*2*y;
		y=0;
	}
	printf("%lld\n",ans+x*a+b*y);
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
  ^
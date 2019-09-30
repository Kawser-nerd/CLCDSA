#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	ll ans=0;
	while(ans<100&&a%2==0&&b%2==0&&c%2==0){
		ll ta=(b+c)/2;
		ll tb=(a+c)/2;
		ll tc=(a+b)/2;
		a=ta;
		b=tb;
		c=tc;
		ans++;
	}
	printf("%lld\n",ans==100?-1:ans);
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
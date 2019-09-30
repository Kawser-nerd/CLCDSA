#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

#define swap(a,b)(t=a,a=b,b=t)

int main(){
	ll a,b,c,t;
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a>b)swap(a,b);
	if(b>c)swap(b,c);
	if(a>b)swap(a,b);
	ll ans=0;
	while(c-a>=2){
		ans++;
		a+=2;
		if(a>b)swap(a,b);
		if(b>c)swap(b,c);
	}
	printf("%lld",ans+(a==c?0:a==b?1:2));
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
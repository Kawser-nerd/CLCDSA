#include <stdio.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))


ll f(ll x,ll y,ll a,ll b,ll t){
	ll dx=llabs(x-a);
	ll dy=llabs(y-b);
	return (dx+dy<=t)&&((dx+dy)%2==t%2);
}

int main(){
	ll n;
	scanf("%lld",&n);
	ll x=0,y=0,t=0;
	ll flag=1;
	rep(i,0,n){
		ll p,q,r;
		scanf("%lld%lld%lld",&p,&q,&r);
		flag&=f(x,y,q,r,p-t);
		t=p;
		x=q;
		y=r;
	}
	puts(flag?"Yes":"No");
} ./Main.c: In function ‘f’:
./Main.c:12:8: warning: implicit declaration of function ‘llabs’ [-Wimplicit-function-declaration]
  ll dx=llabs(x-a);
        ^
./Main.c:12:8: warning: incompatible implicit declaration of built-in function ‘llabs’
./Main.c:12:8: note: include ‘<stdlib.h>’ or provide a declaration of ‘llabs’
./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld",&p,&q,&r);
   ^
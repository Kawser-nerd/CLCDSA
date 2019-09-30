#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll x;
	scanf("%lld",&x);
	ll b=sqrt(x);
	ll ans=1;
	rep(i,2,b+1){
		ll t=i*i;
		while(t<=x){
			ans=max(ans,t);
			t*=i;
		}
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:12:7: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
  ll b=sqrt(x);
       ^
./Main.c:12:7: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:12:7: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&x);
  ^
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll a,b,x;
	scanf("%lld%lld%lld",&a,&b,&x);
	puts(a<=x&&x<=a+b?"YES":"NO");
} ./Main.c: In function �main�:
./Main.c:11:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&x);
  ^
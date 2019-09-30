#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
ll gcd(ll p,ll q){for(ll t;q;)t=p%q,p=q,q=t;return p;}

int main(){
	ll a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	puts(a<=c&&c<=b?"Yes":"No");
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
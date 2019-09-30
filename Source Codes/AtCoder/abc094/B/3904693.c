#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll n,m,x;
	scanf("%lld%lld%lld",&n,&m,&x);
	ll s1=0,s2=0;
	rep(i,0,m){
		ll t;
		scanf("%lld",&t);
		if(t<x)s1++;
		else s2++;
	}
	printf("%lld",min(s1,s2));
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&m,&x);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^
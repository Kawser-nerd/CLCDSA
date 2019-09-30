#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

int main(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	if(a==1||b==1){
		if(a==1&&b==1)puts("Draw");
		else puts(a==1?"Alice":"Bob");
	}else{
		puts(a==b?"Draw":a>b?"Alice":"Bob");
	}
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&b);
  ^
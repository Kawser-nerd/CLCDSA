#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

int main(){
	ll k;
	scanf("%lld",&k);
	puts("50");
	rep(i,0,50)printf("%lld%c",(49+k/50)+(i<k%50?51-k%50:-k%50),i==49?'\n':' ');
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&k);
  ^
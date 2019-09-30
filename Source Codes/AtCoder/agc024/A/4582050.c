#include <stdio.h>
#include <stdlib.h>
#define ll long long int
int main(void){
	ll a,b,c,k,ans;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	if(k%2==0)ans=a-b;
	else ans=b-a;
	
	printf("%lld",ans);
	if(ans>1e18) printf("Unfair");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
  ^
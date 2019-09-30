#include <stdio.h>
int main(void){
	long long int a,b,c;
	scanf("%lld%lld%lld",&a,&b,&c);
	a%=1000000007;
	b%=1000000007;
	c%=1000000007;
	printf("%lld\n",(((a*b)%1000000007)*c)%1000000007);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
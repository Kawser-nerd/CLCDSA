#include <stdio.h>
int main(void){
	long long int a,b,c,hyoumenseki;
	scanf("%lld%lld%lld",&a,&b,&c);
	hyoumenseki=2*(a*b)+2*(b*c)+2*(c*a);
	printf("%lld\n",hyoumenseki);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
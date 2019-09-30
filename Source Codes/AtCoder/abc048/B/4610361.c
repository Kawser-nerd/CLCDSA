#include <stdio.h>
int main(void){
	long long int a,b,x;
	scanf("%lld%lld%lld",&a,&b,&x);
	printf("%lld\n",b/x-a/x+(a%x==0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&x);
  ^
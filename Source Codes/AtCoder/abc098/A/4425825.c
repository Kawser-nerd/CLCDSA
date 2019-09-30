#include <stdio.h>
int main(void){
	long long int a,b;
	scanf("%lld%lld",&a,&b);
	if((a+b)>=(a-b) && (a+b)>=(a*b)) printf("%lld\n",a+b);
	else if((a-b)>=(a+b) && (a-b)>=(a*b)) printf("%lld\n",a-b);
	else printf("%lld\n",a*b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&a,&b);
  ^
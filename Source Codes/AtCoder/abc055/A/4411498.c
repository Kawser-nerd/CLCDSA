#include <stdio.h>
int main(void){
	long long int n;
	scanf("%lld",&n);
	printf("%lld\n",n*800-(n/15)*200);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
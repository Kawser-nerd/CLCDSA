#include <stdio.h>
int main(void){
	long long int n;
	scanf("%lld",&n);
	if(n%2==0) printf("%lld\n",n);
	else printf("%lld\n",n*2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
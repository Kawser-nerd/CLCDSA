#include <stdio.h>
int main(void){
	long long int n;
	scanf("%lld",&n);
	printf("%02lld:%02lld:%02lld\n",n/3600,(n%3600)/60,n%60);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
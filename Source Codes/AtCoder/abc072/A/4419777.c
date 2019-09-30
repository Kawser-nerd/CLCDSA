#include <stdio.h>
int main(void){
	long long int x,t;
	scanf("%lld%lld",&x,&t);
	if(x<t) printf("0\n");
	else printf("%lld\n",x-t);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&x,&t);
  ^
#include <stdio.h>
int main(void){
	long long int w,h;
	scanf("%lld%lld",&w,&h);
	if(w*3==h*4) printf("4:3\n");
	else printf("16:9\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&w,&h);
  ^
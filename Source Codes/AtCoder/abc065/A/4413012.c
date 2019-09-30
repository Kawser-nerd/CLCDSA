#include <stdio.h>
int main(void){
	long long int x,a,b;
	scanf("%lld%lld%lld",&x,&a,&b);
	if(x>=b-a && b<=a) printf("delicious\n");
	else if(x>=b-a && b>a) printf("safe\n");
	else printf("dangerous\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&x,&a,&b);
  ^
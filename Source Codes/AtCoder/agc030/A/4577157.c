#include <stdio.h>
#define ll long long int
int main(void){
	ll a,b,c,max=0;
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a+b < c)max = a+2*b+1;
	else max = b+c;
	printf("%lld",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
#include <stdio.h>
int main(void){
	long long int a,b,c,k,s,t,money;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
	scanf("%lld%lld",&s,&t);
	if(s+t<k){
		money=a*s+b*t;
	}
	if(s+t>=k){
		money=(a-c)*s+(b-c)*t;
	}
	printf("%lld\n",money);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
  ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&s,&t);
  ^
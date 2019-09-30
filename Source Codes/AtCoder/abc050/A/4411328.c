#include <stdio.h>
int main(void){
	long long int a,b;
	char op[2];
	scanf("%lld %s %lld",&a,op,&b);
	if(op[0]=='+') printf("%lld\n",a+b);
	else printf("%lld\n",a-b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %s %lld",&a,op,&b);
  ^
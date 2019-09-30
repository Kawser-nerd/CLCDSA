#include <stdio.h>
int main(void){
	long long int a,b,c,i=0;
	scanf("%lld%lld%lld",&a,&b,&c);
	if(a<=b){
		while(a<=c){
			i++;
			c-=a;
		}
	}
	else{
		while(b<=c){
			i++;
			c-=b;
		}
	}
	printf("%lld\n",i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&a,&b,&c);
  ^
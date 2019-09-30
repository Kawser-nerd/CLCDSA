#include <stdio.h>
#define ll long long int
int main(void){
	ll n,i;
	scanf("%lld",&n);
	for(i=1;i<n;i++){
		if(i*i*i*i==n)break;
	}
	printf("%lld",i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
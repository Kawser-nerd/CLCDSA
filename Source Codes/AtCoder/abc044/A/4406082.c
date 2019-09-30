#include <stdio.h>
int main(void){
	long long int n,k,x,y;
	scanf("%lld%lld%lld%lld",&n,&k,&x,&y);
	if(k>=n) printf("%lld\n",n*x);
	else printf("%lld\n",k*x+(n-k)*y);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&n,&k,&x,&y);
  ^
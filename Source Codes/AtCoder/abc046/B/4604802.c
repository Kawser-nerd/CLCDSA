#include <stdio.h>
int main(void){
	long long int n,k,i,v=1;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<n;i++){
		if(i==0) v*=k;
		else v*=(k-1);
	}
	printf("%lld\n",v);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&n,&k);
  ^
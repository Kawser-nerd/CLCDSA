#include<stdio.h>

int main(){
	long long A,B,C,K;
	scanf("%lld%lld%lld%lld",&A,&B,&C,&K);
	if(K%2==0)printf("%lld\n",A-B);
	else printf("%lld\n",B-A);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld",&A,&B,&C,&K);
  ^
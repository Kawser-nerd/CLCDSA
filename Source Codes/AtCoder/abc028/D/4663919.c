#include <stdio.h>
int main(void){
	double N,K;
	scanf("%lf%lf",&N,&K);
	double p;
	p = ((K-1)*(N-K)*6+(N-1)*3+1)/(N*N*N);
	printf("%.20lf\n",p);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf",&N,&K);
  ^
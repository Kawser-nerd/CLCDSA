#include <stdio.h>

int main(){
	double N;
	scanf("%lf", &N);
	printf("%.12lf\n", (1.8 * N) + 32);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf", &N);
  ^
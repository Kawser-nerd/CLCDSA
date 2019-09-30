#include <stdio.h>
#include <math.h>
int main(void){
	double x;
	scanf("%lf",&x);
	printf("%lld\n",(long long int)(sqrt(sqrt(x))));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&x);
  ^
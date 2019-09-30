#include <math.h>
#include <stdio.h>

int main(void)
{
	double P,res;
	scanf("%lf",&P);
	if ((double)3 / 2 * log2((double)2 * P / 3 * log((double)2)) >= 0)
		res = (double)3 / 2 * log2((double)2 * exp(1) * P / 3 * log((double)2));
	else
		res = P;
	printf("%.10f\n", res);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&P);
  ^
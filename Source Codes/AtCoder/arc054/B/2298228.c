#include <stdio.h>
#include <math.h>

int main(void){
	double p;
	scanf("%lf",&p);
	double x,result;
	if(p != 0){
		x = log2l(2.0*p*logl(2.0)/3.0)*1.5;
		result = x + p/exp2l(x/1.5);
		if(x < 0 || result > p){
			result = p;
		}
	}
	printf("%.10f",result);
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&p);
  ^
#include<stdio.h>
#include<math.h>

int main(void)
{
	double p,x;
	scanf("%lf",&p);
	x=1.5*(log(-1/(p*(1/1.5)*log(0.5)))/log(0.5));
	if(x<=0)
	{
		printf("%lf",p);
		return 0;
	}
	printf("%10.10lf\n",x+p/pow(2.0,x/1.5));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&p);
  ^
#include <stdio.h>

int main(void)
{
	double height,weight,bmi;
	scanf("%lf %lf",&height,&bmi);
	
	height=height/100;
	
	weight=height*height*bmi;
	printf("%lf\n",weight);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&height,&bmi);
  ^
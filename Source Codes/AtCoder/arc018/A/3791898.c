#include <stdio.h>

int main()
{
	double height, bmi;
	scanf("%lf%lf", &height, &bmi);
	printf("%lf\n", (height/100)*(height/100)*bmi);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf", &height, &bmi);
  ^
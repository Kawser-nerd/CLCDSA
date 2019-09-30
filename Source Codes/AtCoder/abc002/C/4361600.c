#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void){
	double x[3],y[3];
	double sides[3];
	double s;
	double ans;
	scanf("%lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
	
	sides[0] = sqrt(pow(x[0]-x[1],2) + pow(y[0]-y[1],2));
	sides[1] = sqrt(pow(x[0]-x[2],2) + pow(y[0]-y[2],2));
	sides[2] = sqrt(pow(x[2]-x[1],2) + pow(y[2]-y[1],2));

	s = (sides[0] + sides[1] + sides[2]) / 2;
	
	ans = sqrt(s*(s-sides[0])*(s-sides[1])*(s-sides[2]));

	printf("%.1f\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf %lf %lf %lf %lf",&x[0],&y[0],&x[1],&y[1],&x[2],&y[2]);
  ^
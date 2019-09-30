#include <stdio.h>
#include <math.h>

double P;

double function(double a);

int main() {

	scanf("%lf", &P);

	double low = 0;
	double high = P;

	double mid;

	while(1){

		if (high - low <0.0000000001) { break; }

		mid = (low + high) / 2.0;

		if (function(mid)*function(low) < 0) {
			high = mid;
		}
		else if (function(mid)*function(low) > 0) {
			low = mid;
		}
	}
	if(fabs(P-low)<0.0000000001){
		printf("%.9lf\n",P);
	}
	else {
		printf("%.9lf\n", low + (P / pow(2.0, low / 1.5)));
	}

	return 0;
}
double function(double a) {
	return 1.0 - ((P*(log(2.0)) / 1.5)*(pow(exp(1.0), -a*((log(2.0)) / 1.5))));
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf", &P);
  ^
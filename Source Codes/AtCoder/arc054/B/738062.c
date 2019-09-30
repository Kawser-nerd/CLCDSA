#include<stdio.h>
#include<math.h>

double f(double p, double x);

int main(void) {
	double p;
	double x, y;
	int i = 0;

	scanf("%lf", &p);
	
	x = 0;
	y = 1000;

	for (i = 0; i < 1000; i++) {
		if (f(p, (2 * x + y) / 3) > f(p, (x + 2 * y) / 3)) {
			x = (2 * x + y) / 3;
		}
		else {
			y = (x + 2 * y) / 3;
		}
	}

	printf("%.10f\n", f(p, x));

	return 0;

}

double f(double p, double x) {
	return x + p * powl(2.0, -x / 1.5);
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf", &p);
  ^
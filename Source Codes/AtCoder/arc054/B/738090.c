#include<stdio.h>
#include<math.h>

int main(void) {
	double p;
	double x, y;
	int i = 0;

	scanf("%lf", &p);

	if (1.5 * log2(p * log(2) / 1.5) >= 0) {
		printf("%.12f\n", 1.5 * log2(p * log(2) / 1.5) + 1.5 / log(2));
	}
	else {
		printf("%.12f\n", p);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf", &p);
  ^
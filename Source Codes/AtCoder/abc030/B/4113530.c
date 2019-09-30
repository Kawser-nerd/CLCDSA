#include <stdio.h>

double max(double a, double b){
	return a > b ? a : b;
}

double min(double a, double b){
	return a < b ? a : b;
}

double dif(double a, double b){
	return max(a, b) - min(a, b);
}

int main(void){
	int n, m;
	scanf("%d %d", &n, &m);
	double a, b;
	b = (double)m / 60;
	a = (double)(n % 12) / 12 + 1.0 / 12 * b;
	if(dif(a, b) <= 0.5)
		printf("%f\n", dif(a, b) * 360);
	else
		printf("%f\n", (1.0 - dif(a, b)) * 360);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
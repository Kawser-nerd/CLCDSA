#include <stdio.h>
#include <stdlib.h>

int main() {
	double n,k,a;
	scanf("%lf %lf", &n, &k);
	a = ((n - k) * (k - 1.0) * 6 + (n - k) * 3 + (k - 1.0) * 3 + 1) / (n * n * n);
	printf("%1.10lf\n", a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf", &n, &k);
  ^
#include<stdio.h>
int main() {
	int n;
	double c;
	scanf("%d", &n);
	c = (9 / 5.0 * n) + 32;
	printf("%f\n", c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
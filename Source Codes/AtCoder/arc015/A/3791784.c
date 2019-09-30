#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	printf("%f\n", (double)(((9.0/5.0)*n)+32.0));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
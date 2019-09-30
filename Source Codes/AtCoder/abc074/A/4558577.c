#include<stdio.h>

int main(void) {
	int x, y;

	scanf("%d", &x);
	scanf("%d", &y);
	printf("%d", x*x - y);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &x);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &y);
  ^
#include <stdio.h>

int main(void) {
	int r, g, b, number;
	scanf("%d %d %d", &r, &g, &b);
	number = 100 * r + 10 * g + b;
	if (number % 4 == 0) {
		printf("YES\n");
	}
	else {
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &r, &g, &b);
  ^
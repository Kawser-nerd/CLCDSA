#include <stdio.h>
#include <math.h>

int main(void) {
	int a, b, c, x, y, money=0;
	scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
	if (2 * c < a + b) {
		if (x < y) {
			money += c*x * 2;
			money += b*(y - x);
			if (money > c*y * 2)money = c*y * 2;
		}
		else {
			money += c*y * 2;
			money += a*(x - y);
			if (money > c*x * 2)money = c*x * 2;
		}
	}
	else {
		money += a*x + b*y;
	}
	printf("%d\n", money);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
  ^
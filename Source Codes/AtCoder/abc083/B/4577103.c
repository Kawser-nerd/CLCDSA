#include <stdio.h>

int sum_digits(int n) {
	int sum = 0;
	do {
		sum += n % 10;
		n = n / 10;
	} while (n >= 1);
	return sum;
}

int main(void) {
	int n, a, b, sum = 0;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 1; i <= n; i++) {
		int _sum = sum_digits(i);
		if ((a <= _sum) && (_sum <= b)) {
			sum += i;
		}
	}
	printf("%d\n", sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d", &n, &a, &b);
  ^
#include <stdio.h>

int examin_money(int *x, int *y, int *z, int N, int SUM) {
	for (int i = 0; i <= N; i++) {
		if (10000 * i > SUM) {
			break;
		}
		for (int j = 0; j <= N - i; j++) {
			if (10000 * i + 5000 * j > SUM) {
				break;
			}
			int total = 10000 * i + 5000 * j + 1000 * (N - i - j);
			if (total == SUM) {
				*x = i;
				*y = j;
				*z = N - i - j;
				return 0;
			}
		}
	}
	*x = *y = *z = -1;
	return 0;
}

int main(void) {
	int x, y, z, n, sum;
	scanf("%d %d", &n, &sum);
	examin_money(&x, &y, &z, n, sum);
	printf("%d %d %d\n", x, y, z);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &sum);
  ^
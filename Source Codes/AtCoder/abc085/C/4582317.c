#include <stdio.h>

int main(void) {
	int n, sum, total;
	scanf("%d %d", &n, &sum);
	for (int i = 0; i <= sum/10000; i++) {
		for (int j = 0; j <= (sum-10000*i)/5000; j++) {
			total = 10000 * i + 5000 * j + 1000 * (n - i - j);
			if (total == sum) {
				printf("%d %d %d\n", i, j, n - i - j);
				return 0;
			}
		}
	}
	printf("-1 -1 -1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &sum);
  ^
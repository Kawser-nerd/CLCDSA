#include <stdio.h>
int main(void){
	int n, m, a, b, c;
	scanf("%d %d", &n, &m);
	if (n * 4 < m || 2 * n > m) {
		printf("-1 -1 -1\n");
		return 0;
	}

	int k;
	for (int i = 0;i <= n;i++) {
		k = m - (2 * n) - i;
		if (k % 2 == 0 && k / 2 + i <= n) {
			b = i;
			c = k / 2;
			a = n - b - c;
			break;
		}
	}
	printf("%d %d %d\n", a, b, c);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &n, &m);
  ^
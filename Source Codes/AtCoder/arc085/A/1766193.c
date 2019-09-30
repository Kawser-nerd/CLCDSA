#include <stdio.h>
// (1800M + 100N) * 2^M
int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", (1800 * m + 100 * n) << m);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n, &m);
  ^
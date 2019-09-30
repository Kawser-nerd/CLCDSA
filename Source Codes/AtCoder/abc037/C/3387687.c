#include <stdio.h>

int main(void)
{
	int N, K, i, j;
	long a[100000], ans = 0;
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; ++i) scanf("%ld", &a[i]);
	for (i = 0; i < N - K + 1; ++i) {
		for (j = 0; j < K; ++j) ans += a[i + j];
	}
	printf("%ld", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:8:26: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for (i = 0; i < N; ++i) scanf("%ld", &a[i]);
                          ^
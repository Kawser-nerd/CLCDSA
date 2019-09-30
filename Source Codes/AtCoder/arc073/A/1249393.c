#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }

int main(void) {
	int i, N, T, t, before_t, ans = 0;
	scanf("%d%d%d", &N, &T, &t);

	for (i = 1; i < N; i++) {
		before_t = t;
		scanf("%d", &t);
		ans += min(t - before_t, T);
	}
	printf("%d\n", ans + T);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &T, &t);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &t);
   ^
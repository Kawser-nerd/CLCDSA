#include <stdio.h>

int main(void)
{
	int N, a, ans = 0, tmp[9] = {0}, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &a);
		if (a >= 3200) ++tmp[8];
		else ++tmp[a / 400];
	}
	for (i = 0; i < 8; ++i) {
		if (tmp[i] > 0) ++ans;
	}
	if (ans == 0) printf("1");
	else printf("%d", ans);
	printf(" %d", ans + tmp[8]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^
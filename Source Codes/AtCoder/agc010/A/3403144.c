#include <stdio.h>

int main(void)
{
	int N, A, sum = 0, i;
	scanf("%d", &N);
	for (i = 0; i < N; ++i) {
		scanf("%d", &A);
		if (A % 2) ++sum;
	}
	if (sum % 2) puts("NO");
	else puts("YES");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^
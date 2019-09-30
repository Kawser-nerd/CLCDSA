#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, i;
	scanf("%d", &N);
	for(i = 2; i <= (int)sqrt(N); ++i) {
		if (N % i == 0) break;
	}
	if (i == (int)sqrt(N) + 1) puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
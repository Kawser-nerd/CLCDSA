#include <stdio.h>

int main(void)
{
	int n;
	int cnt;
	unsigned int candy;

	scanf("%d", &n);

	for (candy = 0, cnt = 1; cnt <= n; cnt++) {
		candy += cnt;
	}

	printf("%d\n", candy);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
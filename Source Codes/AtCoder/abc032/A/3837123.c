#include <stdio.h>

int main()
{
	int a, b, n;
	scanf("%d%d%d", &a, &b, &n);
	int i;
	for (i = n; ; ) {
		if (n % a == 0 && n % b == 0) {
			break;
		}
		n = n+1;
	}
	printf("%d\n", n);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &a, &b, &n);
  ^
#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	if (a + b >= 24) {
		printf("%d\n", a + b - 24);
	} else {
		printf("%d\n", a + b);
	}

	return 0;
} ./Main.c: In function �main�:
./Main.c:6:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &a, &b);
  ^
#include <stdio.h>

int main()
{
	int X, t;
	scanf("%d%d", &X, &t);
	if (X - t > 0) {
		printf("%d\n", X-t);
	} else {
		printf("0\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &X, &t);
  ^
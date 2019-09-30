#include <stdio.h>

int main()
{
	int W, a, b;
	scanf("%d%d%d", &W, &a, &b);
	int i, j;
	int min;
	if (b > a+W) {
		printf("%d\n", b-a-W);
	} else if (a > b+W) {
		printf("%d\n", a-b-W);
	} else {
		printf("0\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &W, &a, &b);
  ^
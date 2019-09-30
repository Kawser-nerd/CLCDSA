#include <stdio.h>

int main()
{
	int A, B, x;
	scanf("%d%d", &A, &B);
	if ( B % A == 0) {
		x = B / A;
	} else {
		x = B / A + 1;
	}
	printf("%d\n", x);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^
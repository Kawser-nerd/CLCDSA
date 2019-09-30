#include <stdio.h>

int main()
{
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if (A < B) {
		printf("%d\n", C / A);
	} else {
		printf("%d\n", C / B);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &C);
  ^
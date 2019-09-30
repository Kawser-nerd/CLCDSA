#include <stdio.h>

int main()
{
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	printf("%d\n", A*B*2 + A*C*2 + B*C*2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &C);
  ^
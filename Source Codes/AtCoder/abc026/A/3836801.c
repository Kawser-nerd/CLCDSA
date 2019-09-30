#include <stdio.h>

int main()
{
	int A;
	scanf("%d", &A);
	printf("%d\n", (A/2)*(A/2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &A);
  ^
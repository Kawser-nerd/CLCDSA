#include <stdio.h>

int main()
{
	int A, B, C;
	scanf("%d%d%d", &A, &B, &C);
	if (C == A+B && C == A-B) {
		printf("?\n");
	} else if (C == A+B && C != A-B) {
		printf("+\n");
	} else if (C == A-B && C != A+B) {
		printf("-\n");
	} else {
		printf("!\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &A, &B, &C);
  ^
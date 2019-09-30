#include <stdio.h>

int main()
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	int i;
	for (i = 0; N > 0; i++) {
		if (i % 2 == 0) {
			N -= A;
		} else {
			N -= B;
		}
	}
	if (i % 2 == 1) {
		printf("Ant\n");
	} else {
		printf("Bug\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^
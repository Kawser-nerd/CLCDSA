#include <stdio.h>

int main()
{
	int N, A, B;
	scanf("%d%d%d", &N, &A, &B);
	int i, counta=0, countb=0;
	for (i = 0; i < 5 && N > 0; i++) {
		N -= 1;
		countb++;
		if (N < 0) {
			break;
		}
	}
	for (; N > 0; N--) {
		counta++;
	}
	printf("%d\n", ((counta) * A) + (countb * B));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &A, &B);
  ^
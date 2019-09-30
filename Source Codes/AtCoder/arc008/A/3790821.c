#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	if (N % 10 == 0) {
		printf("%d\n", N*10);
	} else if (N % 10 > 0 && N % 10 < 7) {
		printf("%d\n", (N-N%10)*10 + 15*(N%10));
	} else if (N % 10 >= 7 && N % 10 <= 9) {
		printf("%d\n", ((N-N%10)+10)*10);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
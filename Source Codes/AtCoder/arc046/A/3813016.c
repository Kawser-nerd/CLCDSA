#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int i, j;
	if (N <= 9 && N >=1) {
		printf("%d\n", N);
	} else if (N >= 10 && N <= 18) {
		printf("%d\n", (N+1-10)*11);
	} else if (N >= 19 && N <= 27) {
		printf("%d\n", (N+1 - 19)*111);
	} else if (N >= 28 && N <= 36) {
		printf("%d\n", (N+1 - 28)*1111);
	} else if (N >= 37 && N <= 45) {
		printf("%d\n", (N+1 - 37)*11111);
	} else if (N >= 46 && N <= 50) {
		printf("%d\n", (N+1 - 46)*111111);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
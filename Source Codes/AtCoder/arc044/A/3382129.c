#include <stdio.h>
#include <math.h>

int main(void)
{
	int N, sum = 0, tmp = 0, i;
	scanf("%d", &N);
	if (N == 1) puts("Not Prime");
	else {
		for (i = 2; i <= (int)sqrt(N); ++i) {
			if (N % i == 0) break;
		}
		if (i == (int)sqrt(N) + 1) puts("Prime");
		else {
			tmp = N;
			do {
				sum += tmp % 10;
			} while (tmp /= 10);
			if (N % 10 % 2 && N % 10 != 5 && sum % 3) puts("Prime");
			else puts("Not Prime");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
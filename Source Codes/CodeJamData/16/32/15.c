#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int B;
unsigned long long M, max;

int main(void)
{
	int i, j, k;
	int T;
	int index;
	unsigned long long t;

	scanf("%d ", &T);
	for (i = 1; i <= T; ++i) {
		scanf("%d %llu ", &B, &M);

		printf("Case #%d: ", i);

		/* calculate max */
		max = 1 << (B-2);

		if (max < M) {
			printf("IMPOSSIBLE\n");
			continue;
		} else
			printf("POSSIBLE\n");

		/* calculate the initial connection */
		if (max == M) {
			/* 0 and then all 1s */
			putchar('0');
			for (j = 1; j < B; ++j)
				putchar('1');
			putchar(10);
		} else {
			putchar('0');

			t = 1 << (B-3);
			while (t) {
				if (t & M)
					putchar('1');
				else
					putchar('0');

				t >>= 1;
			}
			putchar('0');
			putchar(10);
		}

		/* output a KDAG */
		for (j = 2; j <= B; ++j) {
			for (k = 0; k < j; ++k)
				putchar('0');
			for (k; k < B; ++k)
				putchar('1');
			putchar(10);
		}

	}
	return 0;
}


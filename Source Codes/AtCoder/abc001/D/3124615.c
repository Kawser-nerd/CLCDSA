#include <stdio.h>

int main(void)
{
	int i, count = 0, n, s, e, time[289] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d-%d", &s, &e);
		++time[s / 100 * 12 + s % 100 / 5];
		--time[e / 100 * 12 + (e % 100 + 4) / 5];
	}

	for (i = 0; i < 289; ++i) {
		if (!count) {
			if (time[i]) {
				printf("%04d-", i / 12 * 100 + i % 12 * 5);
				count = time[i];
			}
		}
		else {
			if (time[i]) {
				count += time[i];
				if (!count) {
					printf("%04d\n", i / 12 * 100 + i % 12 * 5);
				}
			}
		}
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d-%d", &s, &e);
   ^
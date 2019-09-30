#include <stdio.h>

int main() {
	int t, r, n, i;
	scanf("%d", &t);
	for (i = 1; i <= t; ++i) {
		scanf("%d", &r);
		scanf("%d", &n);
		int j = 0;
		while (1) {
			n -= 2 * r + 1;
			if (n < 0) {
				break;
			}
			r += 2;
			j++;
		}
		printf("Case #%d: %d\n", i, j);
	}
}

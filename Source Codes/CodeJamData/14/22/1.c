#include <stdio.h>
#include <stdlib.h>

int main()
{
	int ts, ti, a, b, k, i, j, x;
	scanf("%d", &ts);
	for (ti = 1; ti <= ts; ti++) {
		x = 0;
		scanf("%d%d%d", &a, &b, &k);
		for (i = 0; i < a; i++) {
			for (j = 0; j < b; j++) {
				if ((i & j) < k) {
					x++;
				}
			}
		}
		printf("Case #%d: %d\n", ti, x);
	}
	return 0;
}

#include <stdio.h>

int alatt[600][600];

int dpt[600][600];

int main(void)
{
	int t, ti, i, j;
	scanf("%d", &t);
	for (i = 0; i < 600; i++) {
		alatt[0][i] = 0;
		alatt[i][0] = 1;
	}
	for (i = 1; i < 600; i++) {
		for (j = 0; j < 600; j++) {
			alatt[i][j] = alatt[i-1][j] + (j ? alatt[i-1][j-1] : 0);
			alatt[i][j] %= 100003;
		}
	}
	i = 2;
	for (ti = 1; ti <= t; ti++) {
		int n, k;
		scanf("%d", &n);
		for (; i <= n; i++) {
			dpt[i][0] = 0;
			dpt[i][1] = 1;
			for (j = 2; j < i; j++) { //i a j-edik
				dpt[i][j] = 0;
				for (k = 1; k < j; k++) { //j a k-adik
					dpt[i][j] += dpt[j][k]*alatt[i-j-1][j-k-1];
					dpt[i][j] %= 100003;
				}
			}
		}
		j = 0;
		for (k = 1; k < n; k++) {
			j += dpt[n][k];
			j %= 100003;
		}
		printf("Case #%d: %d\n", ti, j);
	}
	return 0;
}
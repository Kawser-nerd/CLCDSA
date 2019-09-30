#include <stdio.h>

int max(int a, int b)
{
	if (a > b) {
		return a;
	} else {
		return b;
	}
}

int main()
{
	int t, n, s, p, i, j, k;
	int a[100];
	int b[31][11] = {0};
	int dp[101][101];

	for (i = 0; i <= 30; i++) {
		for (j = 0; j <= 10; j++) {
			if (i % 3 == 0) {
				if (i / 3 >= j) b[i][j] |= 1;
			} else {
				for (k = 10; k >= 1; k--) {
					if (k * 3 - 1 >= i && k * 3 - 2 <= i) {
						if (k >= j) b[i][j] |= 1;

						break;
					}
				}
			}

			for (k = 10; k >= 2; k--) {
				if (k * 3 - 2 >= i && k * 3 - 4 <= i) {
					if (k >= j) b[i][j] |= 2;

					break;
				}
			}
		}
	}

	scanf("%d", &t);

	for (i = 0; i < t; i++) {
		scanf("%d %d %d", &n, &s, &p);

		for (j = 0; j < n; j++) scanf("%d", &a[j]);

		for (j = 0; j <= n; j++) {
			for (k = 0; k <= s; k++) {
				dp[j][k] = 0;
			}
		}
		
		for (j = 0; j < n; j++) {
			for (k = 0; k < s; k++) {
				if (b[a[j]][p] & 1) {
					dp[j + 1][k] = max(dp[j + 1][k], dp[j][k] + 1);
				} else {
					dp[j + 1][k] = max(dp[j + 1][k], dp[j][k]);
				}

				if (b[a[j]][p] & 2) {
					dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k] + 1);
				} else {
					dp[j + 1][k + 1] = max(dp[j + 1][k + 1], dp[j][k]);
				}
			}

			if (b[a[j]][p] & 1) {
				dp[j + 1][s] = max(dp[j + 1][s], dp[j][s] + 1);
			} else {
				dp[j + 1][s] = max(dp[j + 1][s], dp[j][s]);
			}
		}

		printf("Case #%d: %d\n", i + 1, dp[n][s]);
	}

	return 0;
}

#include <stdio.h>

long long int dp[51][51][2501] = {{{1}}};	// i???j??????s?????????

// O(N^3X)???
int main(void)
{
	int i, j, A, N, s, x;
	long long int ans = 0;

	scanf("%d%d", &N, &A);
	for (i = 1; i <= N; i++) {
		scanf("%d", &x);
		for (j = 0; j <= N; j++) {
			for (s = 0; s <= 2500; s++) {
				if (s < x) {
					dp[i][j][s] = dp[i - 1][j][s];
				} else if (j >= 1) {
					dp[i][j][s] = dp[i - 1][j - 1][s - x]	// x???????
								+ dp[i - 1][j][s];			// x??????????
				} 
			}
		}
	}

	for (i = 1; i <= N; i++) {
		ans += dp[N][i][i * A];
	}

	printf("%lld\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &A);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x);
   ^
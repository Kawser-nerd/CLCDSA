#include <stdio.h>
int main(void)
{
	long long int dp[51][5001] = {{0}};		// i???0?????????t - 50 * 50?????????(?????)
	int i, t, A, N, x, y;

	dp[0][2500] = 1;
	scanf("%d%d", &N, &A);
	for (i = 1; i <= N; i++) {
		scanf("%d", &x);
		y = x - A;
		for (t = 0; t <= 5000; t++) {
			if (t - y < 0 || t - y > 5000)
				dp[i][t] = dp[i - 1][t];
			else
				dp[i][t] = dp[i - 1][t] + dp[i - 1][t - y];
		}
	}

	// ??????????????
	printf("%lld\n", dp[N][2500] - 1);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &A);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &x);
   ^
#include <stdio.h>
#include <string.h>

int N, W;
int dp[101][300];

int max(int a, int b) { return a > b ? a : b; }
int min(long long int a, long long int b) {
	long long int tmp;
	tmp = a < b ? a : b;
	if (tmp < 0) tmp = -1;
	return (int)tmp;
}

int main(void) {
	int i, j, k, w1, w, v, ans = 0;
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &N, &W);

	scanf("%d%d", &w1, &v);
	dp[0][0] = 0;
	dp[1][0] = v;
	for (i = 1; i < N; i++) {
		scanf("%d%d", &w, &v);
		w -= w1;
		for (j = i; j >= 0; j--) {
			for (k = 299 - w; k >= 0; k--) {
				if (dp[j][k] != -1) {
					dp[j + 1][k + w] = max(dp[j + 1][k + w], dp[j][k] + v);
				}
			}
		}
	}
	for (i = 0; i <= N; i++) {
		for (j = min(W - (long long int)w1 * i, 299); j >= 0; j--) {
			if (dp[i][j] != -1) {
				ans = max(dp[i][j], ans);
			}
		}
	}
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &W);
  ^
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &w1, &v);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &w, &v);
   ^
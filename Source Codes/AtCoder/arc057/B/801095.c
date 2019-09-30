#include <stdio.h>

int a[2010];

typedef long long ll;

#define INF (1<<30)

int dp[2010][2010];
int s[2010];

int min(int a,int b);

int main() {

	int N, K;

	scanf("%d %d",&N,&K);

	int i,j;

	int sum = 0;

	for (i = 0; i < N; i++) {
		scanf("%d",&a[i]);
		s[i + 1] = s[i] + a[i];
		sum += a[i];
	}
	if (sum == K) {
		printf("1\n");
		return 0;
	}
	for (i = 0; i <= N; i++) {
		for (j = 0; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j <= i; j++) {
			if (dp[i][j] != INF) {
				dp[i + 1][j] = min(dp[i][j],dp[i+1][j]);

				if (i == 0) {
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
				}
				else {
					int tmp = (ll)dp[i][j] * s[i + 1] / s[i] + 1;
					if (tmp <= dp[i][j] + a[i]) {
						dp[i+1][j+1] =min(dp[i + 1][j + 1], tmp);
					}
				}
			}
		}
	}
	int ans = 0;

	for (i = 0; i <= N; i++) {
		if (dp[N][i] <= K) { ans = i; }
	}
	printf("%d\n",ans);

	return 0;
}
int min(int a, int b) {
	if (a >= b) { return b; }
	else { return a; }
} ./Main.c: In function ‘main’:
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^
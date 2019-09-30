#include <stdio.h>

#define INF (1 << 30)

int N, K;
int a[2010], sum[2010];
int dp[2010][2010];	//i??????????j???????????

int min(int n1, int n2){return n1 < n2 ? n1 : n2;}

int main(void)
{
	int i, j, tmp, ans;
	scanf("%d%d", &N, &K);
	for (i = 0; i < N; i++){
		scanf("%d", &a[i]);
		sum[i + 1] = sum[i] + a[i];
	}
	if (sum[N] == K){
		printf("1\n");
		return 0;
	}

	for (i = 0; i <= N; i++){
		for (j = 0; j <= N; j++){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	for (i = 0; i < N; i++){
		for (j = 0; j <= i; j++){
			if (dp[i][j] != INF){
				//??????????(???????)
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
				//?????????
				if (i == 0){
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + 1);
				} else {
					//tmp??????????
					tmp = (long long int)dp[i][j] * sum[i + 1] / sum[i] + 1;
					//tmp?????????????????????
					if (tmp <= dp[i][j] + a[i]){
						dp[i + 1][j + 1] = min(dp[i + 1][j + 1], tmp);
					}
				}
			}
		}
	}

	for (i = 0; i <= N; i++){
		if (dp[N][i] <= K)
			ans = i;
	}
	printf("%d\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^
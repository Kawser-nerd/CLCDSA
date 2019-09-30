#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, a, i, j, k;
	char c[2];
	scanf("%lld", &N);
	int *w = (int *)malloc(sizeof(int) * N);
	int *b = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < 2 * N; i++){
		scanf("%s %lld", c, &a);
		a--;
		if(c[0] == 'W'){
			w[a] = i;
		}
		else{
			b[a] = i;
		}
	}
	int ***dp2 = (int ***)malloc(sizeof(int **) * (N + 1));
	for(i = 0; i <= N; i++){
		dp2[i] = (int **)malloc(sizeof(int *) * 2 * N);
		for(j = 0; j < 2 * N; j++){
			dp2[i][j] = (int *)malloc(sizeof(int) * 2);
		}
	}
	for(j = 0; j < 2 * N; j++){
		for(k = 0; k < 2; k++){
			dp2[N][j][k] = 0;
		}
	}
	for(i = N - 1; i >= 0; i--){
		for(j = 0; j < 2 * N; j++){
			dp2[i][j][0] = dp2[i + 1][j][0];
			if(w[i] < j){
				dp2[i][j][0]++;
			}
			dp2[i][j][1] = dp2[i + 1][j][1];
			if(b[i] < j){
				dp2[i][j][1]++;
			}
		}
	}

/*	for(i = 0; i <= N; i++){
		for(j = 0; j < 2 * N; j++){
			for(k = 0; k < 1; k++){
				printf("dp2[%lld][%lld][%lld] = %lld\n", i, j, k, dp2[i][j][k]);
			}
		}
	}
	printf("\n");
	for(i = 0; i <= N; i++){
		for(j = 0; j < 2 * N; j++){
			for(k = 1; k < 2; k++){
				printf("dp2[%lld][%lld][%lld] = %lld\n", i, j, k, dp2[i][j][k]);
			}
		}
	}
	printf("\n");
*/

	int ***dp = (int ***)malloc(sizeof(int **) * 2 * N);
	for(i = 0; i < 2 * N; i++){
		dp[i] = (int **)malloc(sizeof(int *) * N);
		for(j = 0; j < N; j++){
			dp[i][j] = (int *)malloc(sizeof(int) * 2);
			for(k = 0; k < 2; k++){
				dp[i][j][k] = inf;
			}
		}
	}
	dp[0][0][0] = w[0];
	dp[0][0][1] = b[0];
	for(i = 1; i < 2 * N; i++){
		for(j = 0; j < N; j++){
			if(j <= i && i - j <= N){
//				printf("(i, j) = (%lld, %lld)\n", i, j);
				if(j == 0){
					dp[i][j][0] = dp2[j][w[j]][0] + dp2[i - j][w[j]][1] + dp[i - 1][i - j - 1][1];
					dp[i][j][1] = dp2[j][b[j]][1] + dp2[i - j][b[j]][0] + dp[i - 1][i - j - 1][0];
				}
				else if(j == i){
					dp[i][j][0] = dp2[j][w[j]][0] + dp2[i - j][w[j]][1] + dp[i - 1][j - 1][0];
					dp[i][j][1] = dp2[j][b[j]][1] + dp2[i - j][b[j]][0] + dp[i - 1][j - 1][1];
				}
				else{
					dp[i][j][0] = dp2[j][w[j]][0] + dp2[i - j][w[j]][1] + min(dp[i - 1][j - 1][0], dp[i - 1][i - j - 1][1]);
					dp[i][j][1] = dp2[j][b[j]][1] + dp2[i - j][b[j]][0] + min(dp[i - 1][j - 1][1], dp[i - 1][i - j - 1][0]);
				}
			}
		}
	}
/*	for(i = 0; i < 2 * N; i++){
		for(j = 0; j < N; j++){
			for(k = 0; k < 1; k++){
				printf("dp[%lld][%lld][%lld] = %lld\n", i, j, k, dp[i][j][k]);
			}
		}
	}
	printf("\n");
	for(i = 0; i < 2 * N; i++){
		for(j = 0; j < N; j++){
			for(k = 1; k < 2; k++){
				printf("dp[%lld][%lld][%lld] = %lld\n", i, j, k, dp[i][j][k]);
			}
		}
	}
*/	printf("%lld\n", min(dp[2 * N - 1][N - 1][0], dp[2 * N - 1][N - 1][1]));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %lld", c, &a);
   ^
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int W, N, K, i, k, w;
	scanf("%d%d%d", &W, &N, &K);
	int *A = (int *)malloc(sizeof(int) * (N + 1));
	int *B = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 1; i <= N; i++){
		scanf("%d%d", &A[i], &B[i]);
	}
	int ***dp = (int ***)malloc(sizeof(int **) * (N + 1));
	for(i = 0; i <= N; i++){
		dp[i] = (int **)malloc(sizeof(int *) * (K + 1));
		for(k = 0; k <= K; k++){
			dp[i][k] = (int *)malloc(sizeof(int) * (W + 1));
			for(w = 0; w <= W; w++){
				dp[i][k][w] = 0;
			}
		}
	}
	for(i = 1; i <= N; i++){
		for(k = 0; k <= K; k++){
			for(w = 0; w <= W; w++){
				if(k > 0 && w >= A[i]){
					dp[i][k][w] = max(dp[i - 1][k][w], dp[i - 1][k - 1][w - A[i]] + B[i]);
				}
				else{
					dp[i][k][w] = dp[i - 1][k][w];
				}
			}
		}
	}
	printf("%d\n", dp[N][K][W]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &W, &N, &K);
  ^
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A[i], &B[i]);
   ^
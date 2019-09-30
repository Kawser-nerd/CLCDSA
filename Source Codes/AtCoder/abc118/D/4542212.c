#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, M, i, j, num[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	scanf("%d%d", &N, &M);
	int *A = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d", &A[i]);
	}
	int *dp = (int *)malloc(sizeof(int) * (N + 1));
	dp[0] = 0;
	for(i = 1; i <= N; i++){
		dp[i] = -inf;
		for(j = 0; j < M; j++){
			if(i - num[A[j]] >= 0){
				dp[i] = max(dp[i], dp[i - num[A[j]]] + 1);
			}
		}
	}
	while(N > 0){
		for(i = 0, j = 0; i < M; i++){
			if(N - num[A[i]] >= 0 && dp[N] == dp[N - num[A[i]]] + 1){
				j = max(j, A[i]);
			}
		}
		printf("%d", j);
		N -= num[j];
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^
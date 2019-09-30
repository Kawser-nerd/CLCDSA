#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, x, y, i, j;
	scanf("%d%d", &N, &M);
	int *rab = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		rab[i] = 0;
	}
	for(i = 0; i < M; i++){
		scanf("%d%d", &x, &y);
		rab[y - 1] |= 1 << (x - 1);
	}
	int powN = 1 << N;
	long long int *dp = (long long int *)malloc(sizeof(long long int) * powN);
	dp[0] = 1;
	for(i = 1; i < powN; i++){
		dp[i] = 0;
		for(j = 0; 1 << j <= i; j++){
			if(((1 << j) & i) != 0 && (i & rab[j]) == 0){
				dp[i] += dp[i ^ (1 << j)];
			}
		}
	}
	printf("%lld\n", dp[powN - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &x, &y);
   ^
#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int is_valid(int k, int W){
	int i;
	for(i = 0; i < W - 2; i++){
		if(((k | (1 << i)) == k) && ((k | (1 << (i + 1))) == k)){
			return 0;
		}
	}
	return 1;
}

signed main(){
	int H, W, K, i, j, k;
	scanf("%lld%lld%lld", &H, &W, &K);
	int **dp = (int **)malloc(sizeof(int *) * (H + 1));
	for(i = 0; i <= H; i++){
		dp[i] = (int *)malloc(sizeof(int) * W);
		for(j = 0; j < W; j++){
			dp[i][j] = 0;
		}
	}
	dp[0][0] = 1;
	for(i = 1; i <= H; i++){
//		printf("i = %lld\n", i);
		for(k = 0; k < (1 << (W - 1)); k++){
//			printf("k = %lld\n", k);
			if(is_valid(k, W) == 1){
				for(j = 0; j < W; j++){
//					printf("j = %lld\n", j);
					if((k | (1 << j)) == k){
						if(j < W - 1){
							dp[i][j] = MOD(dp[i][j] + dp[i - 1][j + 1]);
						}
					}
					else if((k | (1 << (j - 1))) == k){
						if(j > 0){
							dp[i][j] = MOD(dp[i][j] + dp[i - 1][j - 1]);
						}
					}
					else{
						dp[i][j] = MOD(dp[i][j] + dp[i - 1][j]);
					}
				}
			}
		}
	}
/*	for(i = 0; i <= H; i++){
		for(j = 0; j < W; j++){
			printf("%lld ", dp[i][j]);
		}
		printf("\n");
	}
*/	printf("%lld\n", dp[H][K - 1]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld", &H, &W, &K);
  ^
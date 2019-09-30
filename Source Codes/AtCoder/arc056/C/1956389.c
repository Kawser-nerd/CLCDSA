#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
	if(a > b) return(a);
	return(b);
}

int min(int a, int b)
{
	if(a < b) return(a);
	return(b);
}

int N, K, W[17][17];
int cost[1 << 17];
int dp[1 << 17];

int rec(int beet)
{
	if(beet == 0) return(0);
	if(~dp[beet]) return(dp[beet]);
	int ret = 0;
	for(int i = beet; i > 0; i = (i - 1) & beet) {
		ret = max(ret, rec(i ^ beet) + cost[i] + cost[i ^ beet] - cost[beet]);
	}
	return(dp[beet] = ret + K);
}

								 
int main()
{
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			scanf("%d", &W[i][j]);
		}
	}
	for(int i = 0; i < (1 << N); i++) {
		for(int j = 0; j < N; j++) {
			for(int k = 0; k < j; k++) {
				if((i >> j) & 1 && (i >> k) & 1) {
					cost[i] += W[j][k];
				}
			}
		}
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", rec((1 << N) - 1));
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d", &N, &K);
  ^
./Main.c:37:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &W[i][j]);
    ^
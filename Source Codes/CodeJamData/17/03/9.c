#include <stdio.h>
#include <string.h>
#include <stdint.h>

int64_t minLR;
int64_t maxLR;

int64_t dp[256][2];	// [size, count]

void dig(int64_t N, int64_t count)
{
	int used = 1, i;
	int64_t k;
	dp[0][0] = N;
	dp[0][1] = 1;
	for(;;){
		for(i = 0; i < used; i++){
			if(dp[i][1]) break;
		}
		minLR = (dp[i][0] - 1) >> 1;
		maxLR = minLR + ((dp[i][0] - 1) & 1);
		if(count <= dp[i][1]) return;
		k = dp[i][1];
		dp[i][1] = 0;
		count -= k;
		//
		for(i = 0; i < used; i++){
			if(dp[i][0] == maxLR) break;
		}
		if(i >= used){
			used++;
			dp[i][0] = maxLR;
			dp[i][1] = 0;
		}
		dp[i][1] += k;
		//
		for(i = 0; i < used; i++){
			if(dp[i][0] == minLR) break;
		}
		if(i >= used){
			used++;
			dp[i][0] = minLR;
			dp[i][1] = 0;
		}
		dp[i][1] += k;
		//
/*		
		printf("\n");
		for(i = 0; i < used; i++){
			printf("%lld %lld\n", dp[i][0], dp[i][1]);
		}
*/		
	}
}

int main(int argc, char *argv[])
{
	int64_t T, N, K;
	int i;
	scanf("%lld", &T);
	for(i = 0; i < T; i++){
		scanf("%lld %lld", &N, &K);
		dig(N, K);
		printf("Case #%d: %lld %lld\n", i + 1, maxLR, minLR);
	}
	return 0;
}

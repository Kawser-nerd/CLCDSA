#include<stdio.h>

int main()
{
	int N, C[30000];
	int i;
	int dp[30001];
	int low, high, mid;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d", &C[i]);
	}

	for(i = 0; i < 30001; i++) {
		dp[i] = N + 1;
	}
	for(i = 0; i < N; i++) {
		low = -1, high = 30000;
		while(high - low > 1) {
			mid = (low + high) / 2;
			if(C[i] < dp[mid]) high = mid;
			else low = mid;
		}
		dp[high] = C[i];
	}
	
	for(i = 0; i <= N; i++) {
		if(dp[i] == N + 1) {
			printf("%d\n", N - i);
			break;
		}
	}
	
	return(0);
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &C[i]);
   ^
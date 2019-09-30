#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int max(int a, int b){
	return a >= b ? a : b;
}

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, i, evensum = 0, oddsum = 0;
	scanf("%d", &N);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &a[i]);
		if(i % 2 == 0){
			evensum += a[i];
		}
		else{
			oddsum += a[i];
		}
	}
	if(N % 2 == 0){
		printf("%d %d\n", max(evensum, oddsum), min(evensum, oddsum));
		return 0;
	}
	int *dp = (int *)malloc(sizeof(int) * ((N + 1) / 2));
	dp[0] = a[0];
	int l = -inf, h, r = inf;
	while(r - l > 1){
		h = (l + r) / 2;
		for(i = 1; 2 * i < N; i++){
			dp[i] = dp[i - 1] + a[2 * i] - a[2 * i - 1];
			if(dp[i - 1] >= h){
				dp[i] = max(dp[i], a[2 * i]);
			}
		}
		if(dp[N / 2] >= h){
			l = h;
		}
		else{
			r = h;
		}
	}
	int ans = max(evensum, oddsum + l);
	printf("%d %d\n", ans, evensum + oddsum - ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a[i]);
   ^
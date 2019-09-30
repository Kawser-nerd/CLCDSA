#include <stdio.h>
#include <stdlib.h>
#define int long long
#define p (int)(1e9 + 7)
#define inf (int)(1e18)

int MOD(int a){
	a %= p;
	return a >= 0 ? a : a + p;
}

int power(int a, int N){
	if(N == 0){
		return 1;
	}
	else if(N % 2 == 0){
		return power(MOD(a * a), N / 2);
	}
	else{
		return MOD(a * power(a, N - 1));
	}
}

signed compare(const void *a, const void *b){
	int sub = *(int *)a - *(int *)b;
	if(sub < 0){
		return -1;
	}
	else if(sub == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int h_to_sec(int x, int *hsub, int H){
	int l = -1, h, r = H;
	while(r - l > 1){
		h = (l + r) / 2;
		if(hsub[h] < x){
			l = h;
		}
		else{
			r = h;
		}
	}
	return r;
}

signed main(){
	int N, H, i, j;
	scanf("%lld", &N);
	int *h = (int *)malloc(sizeof(int) * N);
	int *hsub = (int *)malloc(sizeof(int) * (N + 1));
	for(i = 0; i < N; i++){
		scanf("%lld", &h[i]);
		h[i]--;
		hsub[i] = h[i];
	}
	qsort(hsub, N, sizeof(int), compare);
	hsub[N] = inf;
	for(H = 0, i = 0; i < N; H++){
		hsub[H] = hsub[i];
		while(hsub[H] == hsub[i]){
			i++;
		}
	}
	int *left = (int *)malloc(sizeof(int) * H);
	int *right = (int *)malloc(sizeof(int) * H);
	for(i = 0; i < H; i++){
		right[i] = hsub[i];
	}
	left[0] = 0;
	for(i = 1; i < H; i++){
		left[i] = hsub[i - 1];
	}
/*	for(i = 0; i < H; i++){
		printf("section[%lld] = [%lld, %lld)\n", i, left[i], right[i]);
	}
	printf("\n");
*/	int *dp = (int *)malloc(sizeof(int) * N);
	int **dp2 = (int **)malloc(sizeof(int *) * N);
	int *sec = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		sec[i] = h_to_sec(h[i], hsub, H);
//		printf("sec[%lld] = %lld\n", i, sec[i]);
		dp2[i] = (int *)malloc(sizeof(int) * (sec[i] + 1));
	}
//	printf("\n");
	for(j = 0; j <= sec[0]; j++){
		dp2[0][j] = MOD(power(2, h[0] - left[j] + 1) - power(2, h[0] - right[j] + 1));
	}
	dp[0] = 2;
/*	printf("dp[0] = %lld\n", dp[0]);
	for(j = 0; j <= sec[0]; j++){
		printf("dp2[0][%lld] = %lld\n", j, dp2[0][j]);
	}
	printf("\n");
*/	for(i = 1; i < N; i++){
//		printf("i = %lld\n", i);
		if(h[i] >= h[i - 1]){
//			printf("test3\n");
			dp[i] = MOD(2 * dp[i - 1]);
			for(j = 0; j <= sec[i - 1]; j++){
				dp2[i][j] = MOD(dp2[i - 1][j] * power(2, h[i] - h[i - 1]));
			}
			for(j = j; j <= sec[i]; j++){
				dp2[i][j] = MOD(dp[i - 1] * MOD(power(2, h[i] - left[j] + 1) - power(2, h[i] - right[j] + 1)));
			}
		}
		else{
//			printf("tesst4\n");
			dp[i] = dp[i - 1];
			for(j = sec[i] + 1; j <= sec[i - 1]; j++){
				dp[i] = MOD(dp[i] + dp2[i - 1][j]);
			}
			dp[i] = MOD(2 * dp[i]);
			for(j = 0; j <= sec[i]; j++){
				dp2[i][j] = dp2[i - 1][j];
			}
		}
/*		printf("dp[%lld] = %lld\n", i, dp[i]);
		for(j = 0; j <= sec[i]; j++){
			printf("dp2[%lld][%lld] = %lld\n", i, j, dp2[i][j]);
		}
		printf("\n");
*/	}
	int ans = dp[N - 1];
	for(j = 0; j <= sec[N - 1]; j++){
		ans = MOD(ans + dp2[N - 1][j]);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:53:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &h[i]);
   ^
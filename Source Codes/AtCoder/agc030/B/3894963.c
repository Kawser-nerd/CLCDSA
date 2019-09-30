#include <stdio.h>
#include <stdlib.h>
#define int long long

int max(int a, int b){
	return a >= b ? a : b;
}

signed main(){
	int L, N, i;
	scanf("%lld%lld", &L, &N);
	int *X = (int *)malloc(sizeof(int) * (N + 2));
	int *Y = (int *)malloc(sizeof(int) * (N + 2));
	int *SX = (int *)malloc(sizeof(int) * (N + 2));
	int *SY = (int *)malloc(sizeof(int) * (N + 2));
	for(i = 1; i <= N; i++){
		scanf("%lld", &X[i]);
		Y[i] = L - X[i];
	}
	SX[0] = 0;
	for(i = 1; i <= N; i++){
		SX[i] = SX[i - 1] + X[i];
	}
	SY[N + 1] = 0;
	for(i = N; i >= 1; i--){
		SY[i] = SY[i + 1] + Y[i];
	}
	int l, r, now, ans;
	ans = max(X[N], Y[1]);
	for(i = 1; i < N; i++){
//		printf("i = %lld\n", i);
		l = i;
		r = N - i;
//		k = min(l, r);
//		now = 2 * SX[k]
		if(l < r){
			now = 2 * SX[i];
			now += 2 * (SY[i + 1] - SY[i + 1 + l + 1]) - Y[i + 1];
			ans = max(ans, now);
//			printf("now1 = %lld\n", now);
			now = 2 * SX[i] - X[i];
			now += 2 * (SY[i + 1] - SY[i + 1 + l]);
			ans = max(ans, now);
		}
		if(l > r){
			now = 2 * SY[i + 1];
//			printf("now = %lld\n", now);
//			printf("test:%lld\n", 2 * (SX[i] - SX[i - r - 1]));
			now += 2 * (SX[i] - SX[i - r - 1]) - X[i];
			ans = max(ans, now);
//			printf("now2 = %lld\n", now);
			now = 2 * SY[i + 1] - Y[i + 1];
			now += 2 * (SX[i] - SX[i - r]);
			ans = max(ans, now);

		}
		if(l == r){
			now = 2 * SX[i];
			now += 2 * SY[i + 1] - Y[i + 1];
			ans = max(ans, now);
//			printf("now3 = %lld\n", now);
			now = 2 * SY[i + 1];
			now += 2 * SX[i] - X[i];
			ans = max(ans, now);
//			printf("now4 = %lld\n", now);
		}
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &L, &N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &X[i]);
   ^
#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, M, i, d, dsum = 0, ans = inf;
	scanf("%lld%lld", &N, &M);
	int *a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &a[i]);
	}
	int *x = (int *)malloc(sizeof(int) * (3 * M + 1));
	for(i = 0; i <= 3 * M; i++){
		x[i] = 0;
	}
	for(i = 1; i < N; i++){
		if(a[i - 1] > a[i]){
			a[i - 1] -= M;
		}
		d = a[i] - a[i - 1];
		dsum += d;
		x[M + a[i - 1] + 2] += -1;
		x[M + a[i] + 1] += d;
		x[M + a[i] + 2] += -d + 1;
		x[2 * M + a[i - 1] + 2] += -1;
		x[2 * M + a[i] + 1] += d;
		x[2 * M + a[i] + 2] += -d + 1;
	}
	for(i = 1; i <= 3 * M; i++){
		x[i] += x[i - 1];
	}
	x[0] = dsum;
	for(i = 1; i <= 3 * M; i++){
		x[i] += x[i - 1];
	}
	for(i = M + 1; i <= 2 * M; i++){
//		printf("x[%lld] = %lld\n", i, x[i]);
		ans = min(ans, x[i]);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i]);
   ^
#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e18)

int min(int a, int b){
	return a <= b ? a : b;
}

signed main(){
	int N, x, i, j, sum, ans;
	scanf("%lld%lld", &N, &x);
	int **a = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		a[i] = (int *)malloc(sizeof(int) * N);
		scanf("%lld", &a[i][0]);
	}
	for(i = 0; i < N; i++){
		for(j = 1; j < N; j++){
			a[i][j] = min(a[i][j - 1], a[(i - j + N) % N][0]);
		}
	}
	for(j = 0, ans = inf; j < N; j++){
		for(i = 0, sum = x * j; i < N; i++){
			sum += a[i][j];
		}
		ans = min(ans, sum);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &x);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a[i][0]);
   ^
#include <stdio.h>
#include <stdlib.h>
#define int long long
#define inf (int)(1e13)

int necessary_extension(int *A, int *D, int x, int N){
	int i, ans = 0;
	for(i = 0; i < N; i++){
		if(A[i] < x){
			ans += (x - A[i] - 1 + D[i]) / D[i];
		}
	}
	return ans;
}

signed main(){
	int K, N, i, n;
	int ans = 0;
	scanf("%lld%lld", &K, &N);
	int *A = (int *)malloc(sizeof(int) * N);
	int *D = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld%lld", &A[i], &D[i]);
	}
	int l = 0, h, r = inf;
	while(r - l > 1){
		h = (l + r) / 2;
//		printf("necessary_extension(%lld) = %lld\n", h, necessary_extension(A, D, h, N));
		if(necessary_extension(A, D, h, N) > K){
			r = h;
		}
		else{
			l = h;
		}
	}
//	printf("\n");
//	printf("l = %lld\n", l);
//	printf("necessary_extension(l) = %lld\n", necessary_extension(A, D, l, N));
	for(i = 0; i < N; i++){
		if(A[i] < l){
			n = (l - A[i] - 1 + D[i]) / D[i];
		}
		else{
			n = 0;
		}
//		printf("(i, n) = (%lld, %lld)\n", i, n);
//		ans += (n * (2 * A[i] + (n - 1) * D[i])) / 2;
		if(n % 2 == 0){
			ans += n * A[i] + (n / 2) * (n - 1) * D[i];
		}
		else{
			ans += n * A[i] + n * ((n - 1) / 2) * D[i];
		}
	}
	ans += (K - necessary_extension(A, D, l, N)) * l;
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &K, &N);
  ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &A[i], &D[i]);
   ^
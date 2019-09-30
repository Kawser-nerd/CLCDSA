#include <stdio.h>
#include <stdlib.h>
#define int long long

int *pro(int N, int *p, int *q){
	int i;
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		ans[i] = p[q[i]];
	}
	return ans;
}

int *power(int N, int *p, int K){
	if(K == 1){
		return p;
	}
	else if(K % 2 == 0){
		return power(N, pro(N, p, p), K / 2);
	}
	else{
		return pro(N, p, power(N, p, K - 1));
	}
}

signed main(){
	int N, M, K, a, tmp, i;
	scanf("%lld", &N);
	int *x = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%lld", &x[i]);
	}
	int *p = (int *)malloc(sizeof(int) * (N - 1));
	for(i = 0; i < N - 1; i++){
		p[i] = i;
	}
	scanf("%lld%lld", &M, &K);
	for(i = 0; i < M; i++){
		scanf("%lld", &a);
		tmp = p[a - 2];
		p[a - 2] = p[a - 1];
		p[a - 1] = tmp;
	}
	p = power(N - 1, p, K);
	int *ans = (int *)malloc(sizeof(int) * N);
	ans[0] = x[0];
	for(i = 1; i < N; i++){
		ans[i] = ans[i - 1] + x[p[i - 1] + 1] - x[p[i - 1]];
	}
	for(i = 0; i < N; i++){
		printf("%lld\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &x[i]);
   ^
./Main.c:37:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &M, &K);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &a);
   ^
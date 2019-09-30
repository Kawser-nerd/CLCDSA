#include <stdio.h>
#include <stdlib.h>

int *pro(int N, int *p, int *q){
	int i;
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		ans[i] = q[p[i]];
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

int main(){
	int N, M, D, A, i, tmp;
	scanf("%d%d%d", &N, &M, &D);
	int *p = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		p[i] = i;
	}
	for(i = 0; i < M; i++){
		scanf("%d", &A);
		tmp = p[A - 1];
		p[A - 1] = p[A];
		p[A] = tmp;
	}
	p = power(N, p, D);
	int *ans = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		ans[p[i]] = i + 1;
	}
	for(i = 0; i < N; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:27:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &D);
  ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^
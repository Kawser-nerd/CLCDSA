#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, M, l, r, s, i, sum, A_min;
	scanf("%d%d", &N, &M);
	int *A = (int *)malloc(sizeof(int) * (M + 1));
	for(i = 0; i <= M; i++){
		A[i] = 0;
	}
	for(i = 0, sum = 0; i < N; i++){
		scanf("%d%d%d", &l, &r, &s);
		A[l - 1] += s;
		A[r] -= s;
		sum += s;
	}
	for(i = 1, A_min = A[0]; i < M; i++){
		A[i] += A[i - 1];
		A_min = min(A_min, A[i]);
	}
/*	for(i = 0; i < M; i++){
		printf("A[%d] = %d\n", i, A[i]);
	}
*/	printf("%d\n", sum - A_min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &l, &r, &s);
   ^
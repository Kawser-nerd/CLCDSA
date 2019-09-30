#include <stdio.h>
#include <stdlib.h>

#define e (unsigned int)0xffffffff

unsigned int **matmul(unsigned int **A, unsigned int **B, int N){
	int i, j, k;
	unsigned int **C = (unsigned int **)malloc(sizeof(unsigned int *) * N);
	for(i = 0; i < N; i++){
		C[i] = (unsigned int *)malloc(sizeof(unsigned int) * N);
		for(j = 0; j < N; j++){
			C[i][j] = 0;
			for(k = 0; k < N; k++){
				C[i][j] ^= A[i][k] & B[k][j];
			}
		}
	}
	return C;
}

unsigned int **matpow(unsigned int **A, int N, int k){
	unsigned int **C;
	if(k == 0){
		C = (unsigned int **)malloc(sizeof(unsigned int *) * N);
		int i, j;
		for(i = 0; i < N; i++){
			C[i] = (unsigned int *)malloc(sizeof(unsigned int) * N);
			for(j = 0; j < N; j++){
				if(j == i){
					C[i][j] = e;
				}
				else{
					C[i][j] = 0;
				}
			}
		}
	}
	else if(k % 2 == 0){
		C = matpow(matmul(A, A, N), N, k / 2);
	}
	else{
		C = matmul(A, matpow(A, N, k - 1), N);
	}
	return C;
}

unsigned int main(){
	int K, M, i, j;
	scanf("%d%d", &K, &M);
	unsigned int *A = (unsigned int *)malloc(sizeof(unsigned int) * K);
	for(i = 0; i < K; i++){
		scanf("%u", &A[i]);
	}
	unsigned int **C = (unsigned int **)malloc(sizeof(unsigned int *) * K);
	for(i = 0; i < K; i++){
		C[i] = (unsigned int *)malloc(sizeof(unsigned int) * K);
		scanf("%u", &C[0][i]);
	}
	for(i = 1; i < K; i++){
		for(j = 0; j < K; j++){
			if(i == j + 1){
				C[i][j] = e;
			}
			else{
				C[i][j] = 0;
			}
		}
	}
	if(M <= K){
		printf("%u\n", A[M - 1]);
		return 0;
	}
	C = (matpow(C, K, M - K));
	unsigned int ans = 0;
	for(i = 0; i < K; i++){
		ans ^= C[0][i] & A[K - i - 1];
	}
	printf("%u\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:49:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &K, &M);
  ^
./Main.c:52:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u", &A[i]);
   ^
./Main.c:57:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%u", &C[0][i]);
   ^
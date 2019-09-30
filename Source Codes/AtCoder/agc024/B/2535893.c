#include <stdio.h>
#include <stdlib.h>

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, i;
	scanf("%d", &N);
	int *P = (int *)malloc(sizeof(int) * N);
	int *P_inv = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		scanf("%d", &P[i]);
		P[i]--;
		P_inv[P[i]] = i;
	}
	int *A = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		B[i] = 0;
	}
	B[0] = 1;
	A[0] = 0;
	for(i = 1; i < N; i++){
		if(P_inv[i - 1] < P_inv[i]){
			A[i] = A[i - 1];
		}
		else{
			A[i] = i;
		}
		B[A[i]]++;
	}
	int Bmax = 0;
	for(i = 0; i < N; i++){
//		printf("B[%d] = %d\n", i, B[i]);
		Bmax = max(Bmax, B[i]);
	}
	printf("%d\n", N - Bmax);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &P[i]);
   ^
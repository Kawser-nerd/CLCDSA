#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b, int *A){
	int tmp = A[a];
	A[a] = A[b];
	A[b] = tmp;
}

int main(){
	int N, M, i, odd_num = 0;
	scanf("%d%d", &N, &M);
	int *A = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < M; i++){
		scanf("%d", &A[i]);
		odd_num += A[i] % 2;
	}
	if(M == 1){
		if(A[0] == 1){
			printf("1\n");
			printf("1\n");
			printf("1\n");
		}
		else{
			printf("%d\n", A[0]);
			printf("2\n");
			printf("%d %d\n", 1, A[0] - 1);
		}
		return 0;
	}
	if(odd_num > 2){
		printf("Impossible\n");
		return 0;
	}
	if(odd_num > 0){
		for(i = 0; A[i] % 2 == 0; i++);
		swap(0, i, A);
		for(i = M - 1; A[i] % 2 == 0; i--);
		swap(i, M - 1, A);
	}
	for(i = 0; i < M; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
	int *B = (int *)malloc(sizeof(int) * M);
	B[0] = A[0] - 1;
	for(i = 1; i < M - 1; i++){
		B[i] = A[i];
	}
	B[M - 1] = A[M - 1] + 1;
	if(B[0] == 0){
		printf("%d\n", M - 1);
	}
	else{
		printf("%d\n", M);
		printf("%d ", B[0]);
	}
	for(i = 1; i < M; i++){
		printf("%d ", B[i]);
	}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, M, i, j, ans = 0, old, new;
	scanf("%d%d", &N, &M);
	int *A = (int *)malloc(sizeof(int) * N);
	int *Anum = (int *)malloc(sizeof(int) * N);
	int *B = (int *)malloc(sizeof(int) * N * 2);
	int *X = (int *)malloc(sizeof(int) * M);
	int *Y = (int *)malloc(sizeof(int) * M);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
		A[i]--;
		Anum[i] = 0;
		B[i] = 0;
		B[N + i] = 0;
	}
	for(j = 0; j < M; j++){
		scanf("%d%d", &X[j], &Y[j]);
		X[j]--;
		Y[j]--;
	}
	for(i = 0; i < N; i++){
		B[N + A[i] - Anum[A[i]]]++;
		Anum[A[i]]++;
	}
	for(i = 0; i < N; i++){
		if(B[N + i] == 0){
			ans++;
		}
	}/*
	printf("A: ");
	for(i = 0; i < N; i++){
		printf("%d  ", A[i]);
	}
	printf("\n");
	printf("Anum: ");
	for(i = 0; i < N; i++){
		printf("%d  ", Anum[i]);
	}
	printf("\n");
	printf("B: ");
	for(i = 0; i < 2 * N; i++){
		printf("%d  ", B[i]);
	}
	printf("\n");
	printf("%d\n", ans);
	printf("\n");*/
	for(j = 0; j < M; j++){
		//printf("(X, Y) = (%d, %d)\n", X[j], Y[j]);
		old = A[X[j]];
		new = Y[j];
		A[X[j]] = Y[j];
		Anum[old]--;
		B[N + old - Anum[old]]--;
		if(B[N + old - Anum[old]] == 0 && old - Anum[old] >= 0){
			ans++;
		}
		if(B[N + new - Anum[new]] == 0 && new - Anum[new] >= 0){
			ans--;
		}
		B[N + new - Anum[new]]++;
		Anum[new]++;/*
		printf("A: ");
		for(i = 0; i < N; i++){
			printf("%d  ", A[i]);
		}
		printf("\n");
		printf("Anum: ");
		for(i = 0; i < N; i++){
			printf("%d  ", Anum[i]);
		}
		printf("\n");
		printf("B: ");
		for(i = 0; i < 2 * N; i++){
			printf("%d  ", B[i]);
		}
		printf("\n");*/
		printf("%d\n", ans);
		//printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A[i]);
   ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &X[j], &Y[j]);
   ^
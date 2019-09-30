/*
 ============================================================================
 Name        : ARC_090_C.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int candynum(int* candy1, int*candy2, int down, int N);

int max(int a, int b){
	return a >= b ? a : b;
}

int main(void) {
	int N;
	int i;
	int nedan_all= 0;

	scanf("%d", &N);
	int *A = (int *) malloc(sizeof(int) * N);


	for (i = 0; i < N; i++) {
		scanf("%d",&A[i]);
	}


	nedan_all = abs(A[0])+ abs(A[N-1]);

	for(i = 1 ; i<N; i++){
		nedan_all = nedan_all +abs(A[i]- A[i-1]);
	}

	printf("%d\n", nedan_all-abs(A[0])- abs(A[1]- A[0])+ abs(A[1]));
	for(i = 1; i < N-1; i++){
		printf("%d\n", nedan_all - abs(A[i]-A[i-1] ) - abs(A[i+1]-A[i]) + abs(A[i+1]-A[i-1]));
	}
	printf("%d\n", nedan_all-abs(A[N-1])- abs(A[N-1]- A[N-2])+ abs(A[N-2]));

	return EXIT_SUCCESS;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^
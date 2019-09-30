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
	int ans=0;

	scanf("%d", &N);
	int *candy_1 = (int *) malloc(sizeof(int) * N);
	int *candy_2 = (int *) malloc(sizeof(int) * N);

	for (i = 0; i < N; i++) {
		scanf("%d",&candy_1[i]);
	}
	for (i = 0; i < N; i++) {
		scanf("%d", &candy_2[i]);
	}

	for(i=0; i<N; i++){
		ans = max(ans,candynum(candy_1,candy_2, i,N) );
	}

	printf("%d", ans);

	return EXIT_SUCCESS;
}

int candynum(int* candy1, int* candy2, int down, int N) {
	int j;
	int now;
	now = 0;
	for (j = 0; j <= down; j++) {
		now += candy1[j];
	}
	for (j = down; j < N; j++) {
		now += candy2[j];
	}

	return now;
} ./Main.c: In function ‘main’:
./Main.c:25:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&candy_1[i]);
   ^
./Main.c:33:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &candy_2[i]);
   ^
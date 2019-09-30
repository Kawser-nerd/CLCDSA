#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, M, i, j, k;
	scanf("%d%d", &N, &M);
	int **A = (int **)malloc(sizeof(int *) * N);
	int **B = (int **)malloc(sizeof(int *) * N);
	int *p = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		A[i] = (int *)malloc(sizeof(int) * M);
		B[i] = (int *)malloc(sizeof(int) * M);
		p[i] = 0;
		for(j = 0; j < M; j++){
			scanf("%d", &A[i][j]);
			A[i][j]--;
			B[i][A[i][j]] = j;
		}
	}
	int *count = (int *)malloc(sizeof(int) * M);
	int maxnum, thenval, ans = N;
	for(k = 1; k < M; k++){
//		printf("\nk = %d\n", k);
		for(j = 0; j < M; j++){
			count[j] = 0;
		}
		for(i = 0; i < N; i++){
			count[A[i][p[i]]]++;
		}
/*		for(j = 0; j < M; j++){
			printf("count[%d] = %d\n", j, count[j]);
		}
*/		maxnum = 0;
		for(j = 0; j < M; j++){
			if(count[j] > maxnum){
				maxnum = count[j];
				thenval = j;
			}
		}
//		printf("maxnum = %d\n", maxnum);
//		printf("thenval = %d\n", thenval);
		ans = min(ans, maxnum);
		for(i = 0; i < N; i++){
			A[i][B[i][thenval]] = -1;
/*			int l;
			for(l = 0; l < M; l++){
				printf("%d ", A[i][l]);
			}
			printf("\n");
*/			while(A[i][p[i]] == -1){
				p[i]++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:24:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &A[i][j]);
    ^
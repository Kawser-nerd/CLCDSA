#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int L;
	int R;
}pair;

int compair(const void *a, const void *b){
	int sub = ((pair *)a)->L - ((pair *)b)->L;
	if(sub != 0){
		return sub;
	}
	else{
		return ((pair *)a)->R - ((pair *)b)->R;
	}
}

int main(){
	int N, M, Q, p, q, i, j, k;
	scanf("%d%d%d", &N, &M, &Q);
	pair *ps = (pair *)malloc(sizeof(pair) * M);
	for(i = 0; i < M; i++){
		scanf("%d%d", &ps[i].L, &ps[i].R);
	}
	qsort(ps, M, sizeof(pair), compair);
	int **sum = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		sum[i] = (int *)malloc(sizeof(int) * (N + 1));
		for(j = 0; j <= N; j++){
			sum[i][j] = 0;
		}
	}
	for(i = N - 1, j = M - 1; i >= 0; i--){
		while(j >= 0){
			if(ps[j].L - 1 < i){
				break;
			}
			sum[i][ps[j].R]++;
			j--;
		}
		for(k = 1; k <= N; k++){
			sum[i][k] += sum[i][k - 1];
		}
		for(k = 1; k <= N; k++){
			sum[i][k] += sum[i + 1][k];
		}
	}
/*	for(i = 0; i < N; i++){
		for(j = 0; j <= N; j++){
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}
*/	for(i = 0; i < Q; i++){
		scanf("%d%d", &p, &q);
		printf("%d\n", sum[p - 1][q]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &M, &Q);
  ^
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &ps[i].L, &ps[i].R);
   ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &p, &q);
   ^
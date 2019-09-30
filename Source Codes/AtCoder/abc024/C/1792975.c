#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, D, K, i, j, inf, sup;
	scanf("%d%d%d", &N, &D, &K);
	int *L = (int *)malloc(sizeof(int) * D);
	int *R = (int *)malloc(sizeof(int) * D);
	for(i = 0; i < D; i++){
		scanf("%d%d", &L[i], &R[i]);
	}
	int *S = (int *)malloc(sizeof(int) * K);
	int *T = (int *)malloc(sizeof(int) * K);
	for(i = 0; i < K; i++){
		scanf("%d%d", &S[i], &T[i]);
	}
	for(i = 0; i < K; i++){
		inf = S[i];
		sup = S[i];
		for(j = 0; j <= D; j++){
			if(L[j] <= inf && inf <= R[j]){
				inf = L[j];
			}
			if(L[j] <= sup && sup <= R[j]){
				sup = R[j];
			}
			if(inf <= T[i] && T[i] <= sup){
				printf("%d\n", j + 1);
				break;
			}
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d", &N, &D, &K);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &L[i], &R[i]);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &S[i], &T[i]);
   ^
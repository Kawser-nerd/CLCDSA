#include <stdio.h>
#include <stdlib.h>
#define max_size (int)(1e5 + 1)

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, C, s, t, c, i, j, sum, ans = 0;
	scanf("%d%d", &N, &C);
	int **A = (int **)malloc(sizeof(int *) * C);
	for(i = 0; i < C; i++){
		A[i] = (int *)malloc(sizeof(int) * max_size);
		for(j = 0; j < max_size; j++){
			A[i][j] = 0;
		}
	}
	for(i = 0; i < N; i++){
		scanf("%d%d%d", &s, &t, &c);
		for(j = s; j <= t; j++){
			A[c - 1][j] = 1;
		}
	}
	for(i = 0; i < max_size; i++){
		sum = 0;
		for(j = 0; j < C; j++){
			sum += A[j][i];
		}
		ans = max(ans, sum);
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &C);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &s, &t, &c);
   ^
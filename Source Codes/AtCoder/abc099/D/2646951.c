#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){
	return a <= b ? a : b;
}

int main(){
	int N, C, i, j, k, l, ans = 1000000000;
	scanf("%d%d", &N, &C);
	int **D = (int **)malloc(sizeof(int *) * C);
	for(i = 0; i < C; i++){
		D[i] = (int *)malloc(sizeof(int) * C);
		for(j = 0; j < C; j++){
			scanf("%d", &D[i][j]);
		}
	}
	int **c = (int **)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		c[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			scanf("%d", &c[i][j]);
			c[i][j]--;
		}
	}
	int **cp = (int **)malloc(sizeof(int *) * C);
	for(i = 0; i < C; i++){
//		printf("i = %d\n", i);
		cp[i] = (int *)malloc(sizeof(int) * 3);
		for(j = 0; j < 3; j++){
			cp[i][j] = 0;
		}
		for(k = 0; k < N; k++){
			for(l = 0; l < N; l++){
//				printf("(k, l) = (%d, %d)\n", k, l);
				cp[i][(k + l) % 3] += D[c[k][l]][i];
			}
		}
	}
	for(i = 0; i < C; i++){
		for(j = 0; j < C; j++){
			for(k = 0; k < C; k++){
				if(i != j && j != k && k != i){
					ans = min(ans, cp[i][0] + cp[j][1] + cp[k][2]);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &C);
  ^
./Main.c:15:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &D[i][j]);
    ^
./Main.c:22:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &c[i][j]);
    ^
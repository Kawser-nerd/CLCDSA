#include <stdio.h>
#include <stdlib.h>
#define inf (int)(1e9)

int min(int a, int b){
	return a <= b ? a : b;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int A, B, i, j, x, y, N = 100;
	scanf("%d%d", &A, &B);
	int **d = (int **)malloc(sizeof(int *) * (A + 1));
	int **D = (int **)malloc(sizeof(int *) * (A + 1));
	for(x = 1; x <= A; x++){
		d[x] = (int *)malloc(sizeof(int) * (B + 1));
		D[x] = (int *)malloc(sizeof(int) * (B + 1));
		for(y = 1; y <= B; y++){
			scanf("%d", &d[x][y]);
			D[x][y] = inf;
		}
	}
	int **f = (int **)malloc(sizeof(int *) * (N + 1));
	for(i = 0; i <= N; i++){
		f[i] = (int *)malloc(sizeof(int) * (N + 1));
		for(j = 0; j <= N; j++){
			f[i][j] = 0;
			for(x = 1; x <= A; x++){
				for(y = 1; y <= B; y++){
					f[i][j] = max(f[i][j], d[x][y] - (x * i + y * j));
				}
			}
		}
	}
	for(x = 1; x <= A; x++){
		for(y = 1; y <= B; y++){
			for(i = 0; i <= N; i++){
				for(j = 0; j <= N; j++){
					D[x][y] = min(D[x][y], x * i + y * j + f[i][j]);
				}
			}
			if(d[x][y] != D[x][y]){
				printf("Impossible\n");
				return 0;
			}
		}
	}
	printf("Possible\n");
	printf("%d %d\n", 2 * (N + 1), 2 * N + (N + 1) * (N + 1));
	for(i = 1; i <= N; i++){
		printf("%d %d X\n", i, i + 1);
		printf("%d %d Y\n", N + 1 + i, N + 2 + i);
	}
	for(i = 0; i <= N; i++){
		for(j = 0; j <= N; j++){
			printf("%d %d %d\n", i + 1, 2 * N + 2 - j, f[i][j]);
		}
	}
	printf("%d %d\n", 1, 2 * (N + 1));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &A, &B);
  ^
./Main.c:22:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &d[x][y]);
    ^
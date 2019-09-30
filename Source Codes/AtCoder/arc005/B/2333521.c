#include <stdio.h>
#include <stdlib.h>

int main(){
	int x, y, N = 9, i, j;
	char W[3];
	scanf("%d%d%s", &x, &y, W);
	x--;
	y--;
	int **c = (int **)malloc(sizeof(int *) * 3 * N);
	for(i = 0; i < 3 * N; i++){
		c[i] = (int *)malloc(sizeof(int) * 3 * N);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			scanf("%1d", &c[N + i][N + j]);
			c[    N - i    ][    N - j    ] = c[N + i][N + j];
			c[    N - i    ][    N + j    ] = c[N + i][N + j];
			c[    N - i    ][3 * N - j - 2] = c[N + i][N + j];
			c[    N + i    ][    N - j    ] = c[N + i][N + j];
			c[    N + i    ][3 * N - j - 2] = c[N + i][N + j];
			c[3 * N - i - 2][    N - j    ] = c[N + i][N + j];
			c[3 * N - i - 2][    N + j    ] = c[N + i][N + j];
			c[3 * N - i - 2][3 * N - j - 2] = c[N + i][N + j];
		}
	}
	int ans[4];
	if(W[1] == '\0'){
		if(W[0] == 'R'){
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y][N + x + 1];
			ans[2] = c[N + y][N + x + 2];
			ans[3] = c[N + y][N + x + 3];
		}
		else if(W[0] == 'L'){
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y][N + x - 1];
			ans[2] = c[N + y][N + x - 2];
			ans[3] = c[N + y][N + x - 3];
		}
		else if(W[0] == 'U'){
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y - 1][N + x];
			ans[2] = c[N + y - 2][N + x];
			ans[3] = c[N + y - 3][N + x];
		}
		else{
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y + 1][N + x];
			ans[2] = c[N + y + 2][N + x];
			ans[3] = c[N + y + 3][N + x];
		}
	}
	else{
		if(W[0] == 'R' && W[1] == 'U'){
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y - 1][N + x + 1];
			ans[2] = c[N + y - 2][N + x + 2];
			ans[3] = c[N + y - 3][N + x + 3];
		}
		else if(W[0] == 'R' && W[1] == 'D'){
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y + 1][N + x + 1];
			ans[2] = c[N + y + 2][N + x + 2];
			ans[3] = c[N + y + 3][N + x + 3];
		}
		else if(W[0] == 'L' && W[1] == 'U'){
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y - 1][N + x - 1];
			ans[2] = c[N + y - 2][N + x - 2];
			ans[3] = c[N + y - 3][N + x - 3];
		}
		else{
			ans[0] = c[N + y][N + x];
			ans[1] = c[N + y + 1][N + x - 1];
			ans[2] = c[N + y + 2][N + x - 2];
			ans[3] = c[N + y + 3][N + x - 3];
		}
	}
	printf("%1d%1d%1d%1d\n", ans[0], ans[1], ans[2], ans[3]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%s", &x, &y, W);
  ^
./Main.c:16:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%1d", &c[N + i][N + j]);
    ^
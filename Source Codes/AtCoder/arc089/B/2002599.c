#include <stdio.h>
#include <stdlib.h>

int **can_num;

void set(int x1, int y1, int x2, int y2){
	can_num[x1][y1]++;
	can_num[x1][y2 + 1]--;
	can_num[x2 + 1][y1]--;
	can_num[x2 + 1][y2 + 1]++;
}

int max(int a, int b){
	return a >= b ? a : b;
}

int main(){
	int N, K, i, j, X, Y, ans = 0;
	scanf("%d%d", &N, &K);
	int *x = (int *)malloc(sizeof(int) * N);
	int *y = (int *)malloc(sizeof(int) * N);
	char *c = (char *)malloc(sizeof(char) * N);
	for(i = 0; i < N; i++){
//		printf("i = %d\n", i);
		scanf("%d %d %c", &x[i], &y[i], &c[i]);
	}
	can_num = (int **)malloc(sizeof(int *) * (2 * K + 1));
	for(i = 0; i <= 2 * K; i++){
		can_num[i] = (int *)malloc(sizeof(int) * (K + 1));
		for(j = 0; j <= K; j++){
			can_num[i][j] = 0;
		}
	}
	for(i = 0; i < N; i++){
		X = x[i] % K;
		Y = y[i] % K;
		if((x[i] / K + y[i] / K) % 2 == 1){
			if(c[i] == 'B'){
				c[i] = 'W';
			}
			else{
				c[i] = 'B';
			}
		}
		if(c[i] == 'B'){
			set(0, 0, X, Y);
			set(X + 1, Y + 1, X + K, K - 1);
			set(X + K + 1, 0, 2 * K - 1, Y);
		}
		else{
			set(0, Y + 1, X, K - 1);
			set(X + 1, 0, X + K, Y);
			set(X + K + 1, Y + 1, 2 * K - 1, K - 1);
		}
	}
	for(i = 0; i <= 2 * K; i++){
		for(j = 0; j <= K; j++){
			if(i == 0 && j > 0){
				can_num[i][j] += can_num[i][j - 1];
			}
			else if(i > 0 && j == 0){
				can_num[i][j] += can_num[i - 1][j];
			}
			else if(i > 0 && j > 0){
				can_num[i][j] += can_num[i][j - 1] + can_num[i - 1][j] - can_num[i - 1][j - 1];
			}
			ans = max(ans, can_num[i][j]);
		}
	}
/*	for(i = 0; i <= 2 * K; i++){
		for(j = 0; j <= K; j++){
			printf("can_num[%d][%d] = %d  ", i, j, can_num[i][j]);
		}
		printf("\n");
	}
*/	printf("%d\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %c", &x[i], &y[i], &c[i]);
   ^
#include <stdio.h>

int main(void){
	char board[50][50];
	int n;
	scanf("%d", &n);
	getchar();
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			board[j][n - i - 1] = getchar();
		}
		getchar();
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			putchar(board[i][j]);
		putchar('\n');
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
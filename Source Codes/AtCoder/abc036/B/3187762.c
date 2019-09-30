#include <stdio.h>
#define MAXL 51

int main(void){
	char square[MAXL][MAXL];
	char square_out[MAXL][MAXL];
	int N, i, j;
	
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		fscanf(stdin, "%s", square[i]);
	}
	for(i = N-1; i >= 0; i--){
		// row loop
		for(j = 0; j < N; j++){
			// column loop
			square_out[j][N-1-i] = square[i][j];
		}
	}
	
	for(i = 0; i < N; i++){
		square_out[i][N] = '\0';
		printf("%s\n", square_out[i]);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘fscanf’, declared with attribute warn_unused_result [-Wunused-result]
   fscanf(stdin, "%s", square[i]);
   ^
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i, j;
	int **A = (int **)malloc(sizeof(int *) * 5);
	for(i = 0; i < 5; i++){
		A[i] = (int *)malloc(sizeof(int) * 5);
		for(j = 0; j < 5; j++){
			if(i < 4 && j < 4){
				scanf("%d", &A[i][j]);
			}
			else{
				A[i][j] = 0;
			}
		}
	}
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			if(A[i][j] == A[i + 1][j] || A[i][j] == A[i][j + 1]){
				printf("CONTINUE\n");
				return 0;
			}
		}
	}
	printf("GAMEOVER\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &A[i][j]);
     ^
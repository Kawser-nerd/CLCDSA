#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, L, i, j;
	scanf("%d%d\n", &N, &L);
	char **A = (char **)malloc(sizeof(char *) * (L + 1));
	for(i = 0; i <= L; i++){
		A[i] = (char *)malloc(sizeof(char) * (2 * N + 1));
		A[i][0] = ' ';
		gets(&A[i][1]);
/*		for(j = 1; j < 2 * N; j++){
			scanf("%1c", &A[i][j]);
			if(A[i][j] == '\n'){
				A[i][j] = ' ';
			}
		}
*///		printf("i = %d\n", i);
//		scanf("\n");
		A[i][2 * N] = ' ';
	}
//	scanf("\n");
/*	for(i = 0; i <= L; i++){
		for(j = 0; j <= 2 * N; j++){
			printf("(%d, %d)%c", i, j, A[i][j]);
		}
		printf("\n");
	}
*/	for(j = 1; j < 2 * N; j++){
		if(A[L][j] == 'o'){
			break;
		}
	}
	for(i = L - 1; i >= 0; i--){
		if(A[i][j - 1] == '-'){
			j -= 2;
		}
		else if(A[i][j + 1] == '-'){
			j += 2;
		}
	}
	printf("%d\n", (j + 1) / 2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
   gets(&A[i][1]);
   ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d\n", &N, &L);
  ^
/tmp/cc4iFfKT.o: In function `main':
Main.c:(.text.startup+0x76): warning: the `gets' function is dangerous and should not be used.
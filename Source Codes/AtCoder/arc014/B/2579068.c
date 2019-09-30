#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int N, i, j, f;
	scanf("%d", &N);
	char **W = (char **)malloc(sizeof(char *) * N);
	int *L = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		W[i] = (char *)malloc(sizeof(char) * 21);
		scanf("%s", W[i]);
		for(j = 0; W[i][j] != '\0'; j++){}
		L[i] = j;
	}
	for(i = 1; i < N; i++){
//		printf("i = %d\n", i);
		f = 0;
		for(j = 0; j < i; j++){
			if(strcmp(W[i], W[j]) == 0){
//				printf("test4\n");
				f = 1;
			}
		}
//		printf("%c\n", W[i][0]);
//		printf("%c\n", W[i - 1][L[i - 1] - 1]);
		if(W[i][0] != W[i - 1][L[i - 1] - 1]){
//			printf("test6\n");
			f = 1;
		}
		if(f == 1){
			if(i % 2 == 0){
				printf("LOSE\n");
			}
			else{
				printf("WIN\n");
			}
			return 0;
		}
	}
	printf("DRAW\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", W[i]);
   ^
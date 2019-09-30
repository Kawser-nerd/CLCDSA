#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b){
	return strcmp(*(const char **)a, *(const char **)b);
}

int main(){
	int N, i, j;
	char tmp;
	scanf("%d", &N);
	char **S = (char **)malloc(sizeof(char *) * N);
	int *L = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		S[i] = (char *)malloc(sizeof(char) * 21);
		scanf("%s", S[i]);
		for(L[i] = 0; S[i][L[i]] != '\0'; L[i]++){}
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < L[i] / 2; j++){
			tmp = S[i][j];
			S[i][j] = S[i][L[i] - j - 1];
			S[i][L[i] - j - 1] = tmp;
		}
	}
	qsort(S, N, sizeof(char *), compare);
	for(i = 0; i < N; i++){
		for(L[i] = 0; S[i][L[i]] != '\0'; L[i]++){}
		for(j = 0; j < L[i] / 2; j++){
			tmp = S[i][j];
			S[i][j] = S[i][L[i] - j - 1];
			S[i][L[i] - j - 1] = tmp;
		}
	}
	for(i = 0; i < N; i++){
		printf("%s\n", S[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S[i]);
   ^
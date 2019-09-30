#include <stdio.h>
#include <stdlib.h>
#define max_size (int)(1e5 + 1)

int main(){
	int N, i;
	char *S = (char *)malloc(sizeof(char) * max_size);
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){}
	N = i;
	for(i = (N + 1) / 2; i < N; i++){
		if(S[i] != S[i - 1] || S[N - 1 - i] != S[N - i]){
			printf("%d\n", i);
			return 0;
		}
	}
	printf("%d\n", N);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
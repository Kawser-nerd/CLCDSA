#include <stdio.h>

int main(){
	int N, i;
	char S[101];
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){}
	N = i;
	for(i = 0; i < N; i++){
		if(S[i] != S[N - 1 - i]){
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
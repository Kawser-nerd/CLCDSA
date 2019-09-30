#include <stdio.h>

int main(){
	char S[101];
	int A, B, C, D, i;
	scanf("%s", S);
	scanf("%d%d%d%d", &A, &B, &C, &D);
	for(i = 0; ; i++){
		if(i == A || i == B || i == C || i == D){
			printf("%c", '"');
		}
		if(S[i] == '\0'){
			printf("\n");
			return 0;
		}
		printf("%c", S[i]);
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &A, &B, &C, &D);
  ^
#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, newN, i, j, f;
	scanf("%d", &N);
	char *S = (char *)malloc(sizeof(char) * (N + 1));
	scanf("%s", S);
	for(;;){
		f = 0;
		newN = N;
		for(i = 1; i < N; i++){
			if(S[i - 1] == S[i]){
				S[i - 1] = '.';
				S[i] = '.';
				newN -= 2;
				f = 1;
			}
		}
		for(i = 0, j = 0; i < N; i++){
			if(S[i] != '.'){
				S[j] = S[i];
				j++;
			}
		}
		N = newN;
		for(i = 1; i < N - 1; i++){
			if(S[i - 1] == S[i + 1]){
				S[i - 1] = '.';
				S[i + 1] = '.';
				newN -= 2;
				f = 1;
			}
		}
		for(i = 0, j = 0; i < N; i++){
			if(S[i] != '.'){
				S[j] = S[i];
				j++;
			}
		}
		N = newN;
		if(f == 0){
			if(N % 6 <= 3){
				printf("%d\n", N % 6);
			}
			else{
				printf("%d\n", 6 - N % 6);
			}
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
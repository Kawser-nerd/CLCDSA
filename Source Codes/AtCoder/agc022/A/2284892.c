#include <stdio.h>
#include <stdlib.h>

int main(){
	int N, i, j, k, f;
	int alf[26];
	for(i = 0; i < 26; i++){
		alf[i] = 0;
	}
	char S[27];
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		alf[(int)S[i] - (int)'a'] = 1;
	}
	N = i;
	if(N < 26){
		for(i = 0; i < N; i++){
			printf("%c", S[i]);
		}
		for(i = 0; i < 26; i++){
			if(alf[i] == 0){
				printf("%c\n", (char)((int) 'a' + i));
				return 0;
			}
		}
	}
	else{
		for(i = N - 1; i >= 0; i--){
			for(j = (int)S[i] - (int)'a' + 1; j < 26; j++){
				f = 1;
				for(k = 0; k < i; k++){
					if((int)S[k] - (int)'a' == j){
						f = 0;
					}
				}
				if(f == 1){
					for(k = 0; k < i; k++){
						printf("%c", S[k]);
					}
					printf("%c\n", (char)((int) 'a' + j));
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
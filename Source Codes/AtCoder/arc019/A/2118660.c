#include <stdio.h>

int main(){
	int i;
	char S[9];
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		if(S[i] == 'O' || S[i] == 'D'){
			S[i] = '0';
		}
		else if(S[i] == 'I'){
			S[i] = '1';
		}
		else if(S[i] == 'Z'){
			S[i] = '2';
		}
		else if(S[i] == 'S'){
			S[i] = '5';
		}
		else if(S[i] == 'B'){
			S[i] = '8';
		}
	}
	printf("%s\n", S);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
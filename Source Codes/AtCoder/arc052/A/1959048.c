#include <stdio.h>

int is_number(char c){
	if((int)'0' <= (int)c && (int)c <= (int)'9'){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	int i;
	char S[11];
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		if(is_number(S[i])){
			if(S[i + 1] == '\0' || is_number(S[i + 1]) == 0){
				printf("%c\n", S[i]);
			}
			else{
				printf("%d\n", 10 * ((int)S[i] - (int)'0') + ((int)S[i + 1] - (int)'0'));
			}
			return 0;
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
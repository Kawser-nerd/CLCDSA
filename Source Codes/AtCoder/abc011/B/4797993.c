#include <stdio.h>

int main(){
	int i;
	char S[13];
	scanf("%s", S);
	if((int)S[0] >= (int)'a'){
		S[0] = (char)((int)S[0] - ((int)'a' - (int)'A'));
	}
	for(i = 1; S[i] != '\0'; i++){
		if((int)S[i] < (int)'a'){
			S[i] = (char)((int)S[i] + ((int)'a' - (int)'A'));
		}
	}
	printf("%s\n", S);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
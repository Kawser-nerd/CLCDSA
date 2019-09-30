#include <stdio.h>

int main(){
	int i, f = 0;
	char S[101];
	scanf("%s", S);
	for(i = 0; S[i] != '\0'; i++){
		if(f == 0){
			if(S[i] == 'I' || S[i] == 'i'){
				f++;
			}
		}
		else if(f == 1){
			if(S[i] == 'C' || S[i] == 'c'){
				f++;
			}
		}
		else if(f == 2){
			if(S[i] == 'T' || S[i] == 't'){
				f++;
			}
		}
	}
	if(f == 3){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
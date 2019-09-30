#include <stdio.h>
#include <stdlib.h>

int main(){
	char *S = (char *)malloc(sizeof(char) * 21);
	scanf("%s", S);
	if(S[1] == 'W'){
		if(S[6] == 'B'){
			printf("Mi\n");
		}
		else{
			printf("Si\n");
		}
	}
	else if(S[3] == 'W'){
		if(S[8] == 'B'){
			printf("Re\n");
		}
		else{
			printf("La\n");
		}
	}
	else if(S[5] == 'W'){
		if(S[10] == 'B'){
			printf("Do\n");
		}
		else{
			printf("So\n");
		}
	}
	else{
		printf("Fa\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
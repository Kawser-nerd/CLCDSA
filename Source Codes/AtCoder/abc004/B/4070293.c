#include <stdio.h>

int main(){
	int i, j;
	char c[4][4][2];
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			scanf("%s", c[i][j]);
		}
	}
	for(i = 3; i >= 0; i--){
		for(j = 3; j > 0; j--){
			printf("%c ", c[i][j][0]);
		}
		printf("%c\n", c[i][0][0]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", c[i][j]);
    ^
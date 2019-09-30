#include<stdio.h>
int main(void){
	char c[4][5] = {};
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			scanf("%s", &c[i][j]);
		}
	}
	for(int x = 0; x < 4; x++){
		for(int y = 0; y < 4; y++){
			printf("%c", c[3-x][3-y]);
			if(y < 3){
				printf(" ");
			}
			else if(y == 3){
				printf("\n");
			}
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:6:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s", &c[i][j]);
    ^
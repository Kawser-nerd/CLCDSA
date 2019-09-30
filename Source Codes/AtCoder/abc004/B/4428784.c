#include <stdio.h>
int main(void){
	char s[4][4];
	int i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf(" %c",&s[i][j]);
		}
	}
	for(i=3;i>=0;i--){
		for(j=3;j>=0;j--){
			if(j%4==0) printf("%c",s[i][j]);
			else printf("%c ",s[i][j]);
		}
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c",&s[i][j]);
    ^
#include<stdio.h>

int main(){
	int a[4][4],i,j;
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<4;i++){
		for(j=1;j<4;j++){
			if(a[i][j-1]==a[i][j]){
				puts("CONTINUE");
				return 0;
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=1;j<4;j++){
			if(a[j-1][i]==a[j][i]){
				puts("CONTINUE");
				return 0;
			}
		}
	}
	puts("GAMEOVER");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^
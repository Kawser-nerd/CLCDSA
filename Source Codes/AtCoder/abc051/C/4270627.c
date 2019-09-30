#include<stdio.h>
#include<math.h>
#include<string.h>
int main() {
	int sx,sy,tx,ty,i;
	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
	for(i=0;i<abs(tx-sx);i++){
		printf("R");	
	}
	for(i=0;i<abs(ty-sy);i++){
		printf("U");	
	}
	for(i=0;i<abs(tx-sx);i++){
		printf("L");	
	}
	for(i=0;i<abs(ty-sy);i++){
		printf("D");	
	}
	printf("D");
	for(i=0;i<abs(tx-sx+1);i++){
		printf("R");	
	}
	for(i=0;i<abs(ty-sy+1);i++){
		printf("U");	
	}
	printf("L");
	printf("U");
	for(i=0;i<abs(tx-sx+1);i++){
		printf("L");	
	}for(i=0;i<abs(ty-sy+1);i++){
		printf("D");	
	}
	printf("R");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:12: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
  for(i=0;i<abs(tx-sx);i++){
            ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
  ^
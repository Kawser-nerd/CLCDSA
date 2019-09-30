#include<stdio.h>

int main(){
	int sx,sy,tx,ty,i;
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	for(i=0;i<ty-sy;i++)printf("U");
	for(i=0;i<=tx-sx;i++)printf("R");
	for(i=0;i<=ty-sy;i++)printf("D");
	for(i=0;i<=tx-sx;i++)printf("L");
	printf("U");
	printf("L");
	for(i=0;i<=ty-sy;i++)printf("U");
	for(i=0;i<=tx-sx;i++)printf("R");
	for(i=0;i<=ty-sy;i++)printf("D");
	for(i=0;i<tx-sx;i++)printf("L");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
  ^
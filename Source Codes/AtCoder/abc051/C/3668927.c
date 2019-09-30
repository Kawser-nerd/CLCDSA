#include<stdio.h>

int main(){
	int a,b,sx,sy,tx,ty,i;
	scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
	 a=tx-sx;
	 b=ty-sy;
	for(i=0;i<b;i++) printf("U");
	for(i=0;i<a;i++) printf("R");
	for(i=0;i<b;i++) printf("D");
	for(i=0;i<=a;i++) printf("L");
	for(i=0;i<=b;i++) printf("U");
	for(i=0;i<=a;i++) printf("R");
	printf("DR");
	for(i=0;i<=b;i++) printf("D");
	for(i=0;i<=a;i++) printf("L");
	printf("U\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
  ^
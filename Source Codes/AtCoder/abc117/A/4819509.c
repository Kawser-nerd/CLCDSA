#include<stdio.h>
int main(void){
	float T,X;
	scanf("%f %f",&T,&X);
	float time;
	time=T/X;
	printf("%f",time);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%f %f",&T,&X);
  ^
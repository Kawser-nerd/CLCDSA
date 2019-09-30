#include<stdio.h>

int main(){
		float h,b;
		scanf("%f %f",&h,&b);h=h/(double)100;
		printf("%f\n",(double)h*h*b);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%f %f",&h,&b);h=h/(double)100;
   ^
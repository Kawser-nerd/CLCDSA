#include <stdio.h>

int main(void){
	float a,b;
	scanf("%f %f",&a,&b);
	printf("%f",a/b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%f %f",&a,&b);
  ^
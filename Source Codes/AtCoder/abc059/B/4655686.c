#include<stdio.h>
int main(void)
{
	double a,b;
	scanf("%lf %lf",&a,&b);
	if(a>b){
		printf("GREATER\n");
	}
	else if(a<b){
		printf("LESS\n");
	}
	else{
		printf("EQUAL\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf %lf",&a,&b);
  ^
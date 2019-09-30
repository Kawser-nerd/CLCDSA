#include<stdio.h>

int main(void) {
	double i,num,wari,sum=0;
	for(i=0;i<3;i++) {
		scanf("%lf %lf",&num,&wari);
		sum += num*(wari/10);
	}
	printf("%g\n",sum);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&num,&wari);
   ^
#include <stdio.h>

int main(){
	int a,b,i;
	double sum;
	for(i=0;i<3;i++){
		scanf("%d %d\n",&a,&b);
		sum += a*b*0.1;
	}
	
	printf("%.0f\n",sum);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n",&a,&b);
   ^
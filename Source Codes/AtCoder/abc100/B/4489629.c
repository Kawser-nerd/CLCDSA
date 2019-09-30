#include <stdio.h>
#include <math.h>

int main(void)
{
	int d,n;
	
	scanf("%d%d",&d,&n);
	
	if(n==100){
		n=101;
	}
	
	int result=pow(100,d);
	
	printf("%d\n",result*n);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&d,&n);
  ^
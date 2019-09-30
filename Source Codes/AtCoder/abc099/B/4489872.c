#include <stdio.h>

int main(void)
{
	int a,b,x;
	int sum=0;
	
	scanf("%d%d",&a,&b);
	
	x=b-a;
	
	for(int i=0;i<=x;i++){
		sum=sum+i;
	}
	
	printf("%d\n",sum-b);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^
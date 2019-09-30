#include <stdio.h>

int main(void)
{
	int a,b,ave;
	
	scanf("%d %d",&a,&b);
	
	if((a+b)%2==0){
		
		ave=(a+b)/2;
		
	}else{
		
		ave=(a+b+1)/2;
		
	}
	
	printf("%d\n",ave);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^
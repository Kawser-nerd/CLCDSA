#include <stdio.h>

int main(void)
{
	int a,b,h;
	
	scanf("%d\n%d\n%d",&a,&b,&h);
	
	printf("%d\n",(a+b)*h/2);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d\n%d",&a,&b,&h);
  ^
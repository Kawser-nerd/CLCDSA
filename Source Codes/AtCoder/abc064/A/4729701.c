#include<stdio.h>
int main(void)
{
	int r,g,b,i;
	scanf("%d%d%d",&r,&g,&b);
	i=g*10+b;
	
	if(i%4==0)
		printf("\nYES\n\n");
	else 
		printf("\nNO\n\n");
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&r,&g,&b);
  ^
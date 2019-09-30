#include<stdio.h>
int main(void)
{
	int N,A,i;
	scanf("%d",&N);
	scanf("%d",&A);
	i=N%500;
	
	if(i<=A)
		printf("\nYes\n\n");
	else 
		printf("\nNo\n\n");
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&A);
  ^
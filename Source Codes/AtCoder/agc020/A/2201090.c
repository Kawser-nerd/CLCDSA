#include <stdio.h>

int main(void)
{
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	if((B-A+1)%2==0)
	printf("Borys");
	else
	printf("Alice");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&N,&A,&B);
  ^
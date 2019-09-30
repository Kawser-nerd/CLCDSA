#include <stdio.h>

int main(void)
{
	int n,m;
	
	scanf("%d %d",&n,&m);
	
	printf("%d\n",(n-1)*(m-1));
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&m);
  ^
#include <stdio.h>

int main(void)
{
	int n=0;
	int x;
	
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		x=x+i;
	}
	
	printf("%d\n",x);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
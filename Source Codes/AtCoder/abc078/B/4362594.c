#include <stdio.h>

int main(void)
{
	int x,y,z,i=1;
	scanf("%d%d%d",&x,&y,&z);
	while(x/(i*(y+z)+z) > 0)
		{i++;}
	printf("%d\n",i-1);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&x,&y,&z);
  ^
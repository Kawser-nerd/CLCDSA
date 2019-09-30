#include <stdio.h>

int main(void)
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	printf("%d\n",(x-z)/(y+z));
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&x,&y,&z);
  ^
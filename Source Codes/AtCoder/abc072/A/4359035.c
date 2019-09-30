#include <stdio.h>

int main(int argc, char const *argv[])
{
	int x,t;
	scanf("%d%d",&x,&t);
	if(x <= t)	printf("0\n");
	else printf("%d\n", x - t);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&x,&t);
  ^
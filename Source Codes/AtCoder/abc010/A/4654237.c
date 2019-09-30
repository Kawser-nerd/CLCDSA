#include<stdio.h>
int main(void)
{
	char a[10];
	scanf("%s",a);
	printf("%spp\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",a);
  ^
#include <stdio.h>

int main(void)

{
	char c;
	scanf("%c",&c);
	
	printf("%d\n",c-64);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&c);
  ^
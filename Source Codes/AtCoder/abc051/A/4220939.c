#include <stdio.h>

int main(void)
{
	char str[200];
	scanf("%s",str);
	str[5] = ' ';
	str[13] = ' ';
	printf("%s",str);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^
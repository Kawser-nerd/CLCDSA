#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[101];
	scanf("%s",s);
	int len=strlen(s);
	int mid=len-2;
	printf("\n%c%d%c\n",s[0],mid,s[len-1]);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
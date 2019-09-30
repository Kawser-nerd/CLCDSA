#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char s[100001];
	scanf("%s",s);
	int len=strlen(s);
	for(i=0;i<=len-1;i+=2)
		{printf("%c",s[i]);}
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
#include <stdio.h>

int main(void)
{
	char s[100];
	int i;
	
	scanf("%s\n%d",s,&i);
	
	printf("%c\n",s[i-1]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s\n%d",s,&i);
  ^
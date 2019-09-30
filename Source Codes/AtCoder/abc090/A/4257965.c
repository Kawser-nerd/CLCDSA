#include <stdio.h>

int main(void)
{
	char s[3][4];
	scanf("%s%s%s",s[0],s[1],s[2]);
	fprintf(stderr,"%s\n%s\n%s\n",s[0],s[1],s[2]);
	printf("%c%c%c",s[0][0],s[1][1],s[2][2]);

	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s%s",s[0],s[1],s[2]);
  ^
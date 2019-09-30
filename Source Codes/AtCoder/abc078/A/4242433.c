#include <stdio.h>

int main(void)
{
	char s1[10],s2[10];
	scanf("%s%s",s1,s2);

	if(s1[0] == s2[0])
		{printf("=\n");}
	if(s1[0] < s2[0])
		{printf("<\n");}
	if(s1[0] > s2[0])
		{printf(">\n");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s1,s2);
  ^
#include <stdio.h>

int main(void)
{
	char s1[3],s2[3];
	scanf("%s%s",s1,s2);
	if(s1[0] == s2[2] && s1[1] == s2[1] && s1[2] == s2[0])
		{printf("YES");}
	else
		{printf("NO");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",s1,s2);
  ^
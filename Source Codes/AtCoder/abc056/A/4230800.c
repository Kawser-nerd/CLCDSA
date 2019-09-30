#include <stdio.h>

int main(void)
{
	char str1[2],str2[2];
	scanf("%s%s",str1,str2);
	if(str1[0] == 'H')
		{
		if(str2[0] == 'H')
			{printf("H");}
		else
			{printf("D");}
		}
	else
		{
		if(str2[0] == 'H')
			{printf("D");}
		else
			{printf("H");}
		}
			
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%s",str1,str2);
  ^
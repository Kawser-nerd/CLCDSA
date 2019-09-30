#include <stdio.h>

int main(void)
{
	int i=0,count=1;
	char s[4];
	scanf("%s",s);
	for(i;i <= 2;i++)
		{
		if(s[i] == s[i+1])
			{count++;}
		else
			{count=1;}
		if(count == 3)
			{break;}
		}
	if(count == 3)
		{printf("Yes");}
	else
		{printf("No");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[3];
	scanf("%s",s);
	int i,sum=700;
	for(i=0;i<=2;i++)
		{if(s[i]=='o'){sum+=100;}}
	printf("%d",sum);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
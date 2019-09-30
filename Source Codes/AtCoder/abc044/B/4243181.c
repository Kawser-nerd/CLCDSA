#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[100];
	scanf("%s",s);
	int k=strlen(s);
	
	int i=0,j=0,count=0;
	for(i;i <= k-1;i++)
		{
		count=0,j=0;
		for(j;j<=k-1;j++)
			{
			if(s[i] == s[j])
				{count++;}
			}
		if(count%2 != 0)
			{
			printf("No\n");
			break;
			}
		}
	if(count%2 == 0)
		{printf("Yes\n");}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
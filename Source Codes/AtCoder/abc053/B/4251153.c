#include <stdio.h>

char s[200001];
int main(void)
{
	scanf("%s",s);
	int i=0,start=0,count=0,last=0;
	for(i;i <= 199999;i++)
	{
		if(s[i]=='A')
		{
			if(start==0 && count == 0)
			{
				start=i;
				count++;
			}
		}
		else if(s[i]=='Z')
		{last=i;}
	}
	int len=last-start+1;
	printf("%d\n",len);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
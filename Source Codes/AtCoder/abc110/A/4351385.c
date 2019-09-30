#include <stdio.h>

int main(void)
{
	int s[3];
	int i,j,temp;
	scanf("%d%d%d",&s[0],&s[1],&s[2]);
	for(i=1;i>=0;i--)
		{
		for(j=0;j<=i;j++)
			{
			if(s[j]<s[j+1])
				{
				temp=s[j];
				s[j]=s[j+1];
				s[j+1]=temp;
				}
			}
		}
	printf("%d",10*s[0]+s[1]+s[2]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&s[0],&s[1],&s[2]);
  ^
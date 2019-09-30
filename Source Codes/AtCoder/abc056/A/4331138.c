#include<stdio.h>
#include<string.h>
int main()
{
	char m,n;
	scanf("%c %c",&m,&n);
	if(m == 'H')
	{
		if(n == 'H')
		{
			printf("H\n");
		}
		else
		{
			printf("D\n");
		}
	}
	else
	{
		if(n == 'H')
		{
			printf("D\n");
		}
		else
		{
			printf("H\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&m,&n);
  ^
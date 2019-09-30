#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	char s[n];
	scanf("%s",s);
	int x=0,i=0,max=0;
	for(i;i<=n-1;i++)
		{
		if(s[i]=='I')
			{x++;
			if(x>max){max=x;}
			}
		else
			{x--;}
		}
	printf("%d\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
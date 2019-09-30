#include<stdio.h>
int main()
{
	int k,s;
	scanf("%d %d",&k,&s);
	int i,j,l;
    int count = 0;
	int number;
	for(i = 0;i<=k;i++)
	{
		for(j = 0;j<=k;j++)
		{
			if(s-i-j >= 0&& s-i-j<=k) count++;
		}
	}
	printf("%d",count);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&k,&s);
  ^
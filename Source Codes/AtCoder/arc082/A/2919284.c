#include<stdio.h>

int main()
{
	int N,s,i;
	int a[100005]={0};
	while(scanf("%d",&N)!=EOF)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d",&s);
			if(s==0)
			{
				a[s]++;
				a[s+1]++;
			}
			else
			{
				a[s]++;
				a[s+1]++;
				a[s-1]++;
			}
		}
		int max=0;
		for(i=0;i<=100000;i++)
			if(max<a[i]) max=a[i];
		printf("%d\n",max);
	}
	
} ./Main.c: In function ‘main’:
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&s);
    ^
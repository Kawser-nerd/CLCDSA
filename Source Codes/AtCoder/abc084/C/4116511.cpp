#include<stdio.h>
int main()
{
	int n;
	int C[500],S[500],F[500];
	int	time[500]; 
	int i,j;
	while(scanf("%d",&n)!=-1)
	{
		for(i=0;i<n-1;i++)
		{
			scanf("%d%d%d",&C[i],&S[i],&F[i]);
			time[i]=S[i];									//????? 
		}
		for(i=0;i<n-1;i++)									//?n?????????????? 
		{
			for(j=i;j<n-1;j++)
			{
				while(!(time[i]%F[j]==0)||time[i]<S[j]) 
				{
					time[i]++;
				}
				time[i]+=C[j];
				
			}
		}
		for(i=0;i<n-1;i++)
		{
			printf("%d\n",time[i]);
		}
		printf("%d\n",0);						//?? 
	}
}
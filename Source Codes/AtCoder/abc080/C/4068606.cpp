#include<stdio.h>
void make(int *a,int b)
{
	int i;
	for(i=0;i<10;i++)
	{
		a[i]=b%2;
		//printf("%d ",a[i]);
		b=b>>1;
	}
	
}
int maxof(int *a)
{
	int n,i=0;
	int max=a[0];
	for(;i<1023;i++)
	{
		if(a[i]>max)
		max=a[i];
	}
	return max;
}
int bothOpen(int *a,int *b)
{
	int sum=0,i;
	for(i=0;i<10;i++)
	{
		if(a[i]&&b[i])sum++;
	 } 
	return sum;
}
int main()
{
	int sumProfit[1023];							
	int p[100][11];		
	int n,j,k,convey[10],i;						
	int f[100][10];
	int a[10];							//??????? 
	while(scanf("%d",&n)!=-1)
	{									
		for(i=0;i<n;i++)
		{
			for(j=0;j<10;j++)
			scanf("%d",&f[i][j]);
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<11;j++)
			scanf("%d",&p[i][j]);
		}
		
		for(i=1;i<1024;i++)
		{
			sumProfit[i-1]=0;
			make(a,i);
			for(j=0;j<n;j++)
			{
				for(k=0;k<10;k++)
				convey[k]=f[j][k];
				
				sumProfit[i-1]+=p[j][bothOpen(a,convey)];
			}
			
			
		} 
		printf("%d\n",maxof(sumProfit));
	}
}
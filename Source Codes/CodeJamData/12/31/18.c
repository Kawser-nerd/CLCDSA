#include<stdio.h>
#include<string.h>
int a[1003][1003],b[1003],n,flag=0;
find(int i)
{
int j;
	for(j=1;j<=n;j++)
	{
				if(a[i][j]==1)
				{	
					b[j]++;
					if(b[j]>1)
					{
						flag=1;
						break;
					}
					find(j);
				}
	}
	return(0);
}
int main()
{
freopen("A-large.in","r",stdin);
freopen("output.txt","w",stdout);
int t,k,v,m,i,j;
	scanf("%d",&t);
	k=1;
	while(k<=t)
	{	
		memset(a,0,sizeof(a));
		flag=0;
		printf("Case #%d: ",k);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(j=1;j<=m;j++)
			{
				scanf("%d",&v);
				a[i][v]=1;
			}
		}
			
		for(i=1;i<=n;i++)
		{	
			memset(b,0,sizeof(b));
			for(j=1;j<=n;j++)
			{
				if(a[i][j]==1)
				{	
					b[j]++;
					if(b[j]>1)
					{flag=1;goto sis;}
					find(j);
				}
			}
		}
		sis: ;
		if(flag==1)
		printf("Yes\n");
		else printf("No\n");
		k++;
	}
	return(0);
}
	




#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include 	<regex.h>
#include 	<math.h>
int E[1010]={0,0,2,3},a[1010],vis[1010];
double sum;
int main ( int argc, char *argv[] )
{
	int i,tc,j;
	for(i=4;i<1010;i++)E[i]=i;
	scanf("%d",&tc);
	for(i=0;i<tc;i++)
	{
		int n;
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d",&a[j]);
		}
		memset(vis,0,sizeof(vis));
		sum=0.0;
		for(j=1;j<=n;j++)
		{
			if(!vis[j])
			{
				int k=a[j],c=1;
				vis[j]=1;
				while(k!=j){vis[k]=1;c++;k=a[k];}
				sum+=E[c];
			}
		}
		printf("Case #%d: %f\n",i+1,sum);

	}
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */

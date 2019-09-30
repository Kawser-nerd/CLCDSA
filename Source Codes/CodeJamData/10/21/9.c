#include <stdio.h>
int main()
{
	int i,j,k,n,T,N,M,maxK,ans;
	char path[200][101];
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d %d",&N,&M);
		ans=0;
		for(j=0;j<N;j++)
			scanf("%s",path[j]);
		for(j=0;j<M;j++)
		{
			scanf("%s",path[N+j]);
			maxK=0;
			for(n=0;n<N+j;n++)
			{
				for(k=0;path[N+j][k]!='\0'&&path[n][k]!='\0';k++)
					if(path[N+j][k]!=path[n][k])
						break;
				if(path[N+j][k]=='/'&&path[n][k]!='\0')
					k--;
				if(!(path[N+j][k]=='\0'&&(path[n][k]=='\0'||path[n][k]=='/')))
				{
					while(path[N+j][k]!='/')
						k--;
				}
				if(maxK<k)
					maxK=k;
			}
			for(k=maxK;path[N+j][k]!='\0';k++)
				if(path[N+j][k]=='/')
					ans++;
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}


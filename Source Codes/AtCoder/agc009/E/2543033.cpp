#include<cstdio>
int f[4333][4333];
int s[2333];
int main()
{
	int n,m,k,p;
	!scanf("%d%d%d",&n,&m,&k);
	for(int p=k;p<=n+m;p+=k-1)
	{
		for(int i=1;i<=n;i++)
		{
			if(p-i<1)break;
			int r=i-(k-1)>0?i-(k-1):0;
			f[i][p-i]=(s[i+1]-s[r]+1000000008)%1000000007;
		}
		for(int i=0;i<=n;i++)s[i+1]=(s[i]+f[i][p-i])%1000000007;
	}
	printf("%d",f[n][m]);
	return 0;
} ./Main.cpp:7:2: warning: expression result unused [-Wunused-value]
        !scanf("%d%d%d",&n,&m,&k);
        ^~~~~~~~~~~~~~~~~~~~~~~~~
1 warning generated.
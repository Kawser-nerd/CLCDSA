#include<cstdio>
int count=0;
int T;
void dfs(long long n,char flag357)
{
	if(n<=T)
	{
		if(flag357==07)
		count++;
		dfs(n*10+3,flag357|01);
		dfs(n*10+5,flag357|02);
		dfs(n*10+7,flag357|04);
	}
}

int main()
{
	char flag357;
	scanf("%d",&T);
	dfs(0,0);
	printf("%d\n",count);
	return 0;
}
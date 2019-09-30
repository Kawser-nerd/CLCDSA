#include<cstdio>
int n,count=0;
void dfs(long long nextnum,unsigned char flag357)
{
	if(nextnum<=n)
	{
		if(flag357==7)//7??????111
			count++;
		dfs(nextnum*10+3,flag357|1);//1?????001
		dfs(nextnum*10+5,flag357|2);//2?????010
		dfs(nextnum*10+7,flag357|4);//4?????100
	}
}
int main()
{
	scanf("%d",&n);
	dfs(0,0);
	printf("%d\n",count);
	return 0;
}
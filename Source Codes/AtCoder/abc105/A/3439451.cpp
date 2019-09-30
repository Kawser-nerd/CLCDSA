#include<cstdio>
int n,k;
int main()
{
	scanf("%d%d",&n,&k);
	printf("%d",(n%k==0)?0:1);
}
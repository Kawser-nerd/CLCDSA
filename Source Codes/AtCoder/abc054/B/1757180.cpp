#include<cstdio>
#include<cstring>
using namespace std;
char x[55][55],y[55][55];
char st[100],sy[2505],sx[2505];
int m,n;
bool cmp(int a,int b)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i+a-1][j+b-1]!=y[i][j])
			{
				return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",st);
		for(int j=0;j<m;j++)
		{
			x[i][j+1]=st[j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",st);
		for(int j=0;j<n;j++)
		{
			y[i][j+1]=st[j];
		}
	}
	int cha=m-n+1;
	for(int i=1;i<=cha;i++)
	{
		for(int j=1;j<=cha;j++)
		{
			if(cmp(i,j)) 
			{
				printf("Yes");
				return 0;
			}
		}
	}
	printf("No");
	return 0;
}
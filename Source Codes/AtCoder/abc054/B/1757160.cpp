#include<cstdio>
using namespace std;
int n,m;
char a[55][55],b[55][55];
bool check(int x,int y)
{
	for(int k=x;k<=x+m-1;k++)
	for(int r=y;r<=y+m-1;r++)
	{
		if(a[k][r]!=b[k+1-x][r+1-y])return false;
	}
	return true;
}
int main()
{
	char h[55];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",h);
		for(int j=1;j<=n;j++)
		a[i][j]=h[j-1];
    }
    for(int i=1;i<=m;i++)
	{
		scanf("%s",h);
		for(int j=1;j<=m;j++)
		b[i][j]=h[j-1];
    }
    for(int i=1;i<=n-m+1;i++)
    {
    	for(int j=1;j<=n-m+1;j++)
    	{
    		if(check(i,j))
    		{
    			printf("Yes");
    			return 0;
    		}
    	}
    }
    printf("No");
    return 0;
}
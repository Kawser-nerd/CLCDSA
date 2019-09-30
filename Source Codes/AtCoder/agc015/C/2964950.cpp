#include<iostream>
#include<cstdio>
#define N 2010
using namespace std;

int n,m,Q,qz[N][N],ha[N][N],lie[N][N];
bool mm[N][N];
char str[N];

int main()
{
	int i,j,a,b,c,d;
	cin>>m>>n>>Q;
	for(i=1;i<=m;i++)
	{
		scanf("%s",str+1);
		for(j=1;j<=n;j++)
		{
			mm[i][j]=(str[j]=='1');
		}
		for(j=1;j<n;j++) if(mm[i][j]==mm[i][j+1]&&mm[i][j]) ha[i][j]=1;
		if(i>=2)
			for(j=1;j<=n;j++) if(mm[i][j]==mm[i-1][j]&&mm[i][j]) lie[i-1][j]=1;
	}
//	for(i=1;i<=m;i++){for(j=1;j<=n;j++) cout<<lie[i][j]<<" ";puts("");}return 0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			qz[i][j]=qz[i-1][j]+qz[i][j-1]-qz[i-1][j-1]+mm[i][j];
			ha[i][j]+=ha[i-1][j]+ha[i][j-1]-ha[i-1][j-1];
			lie[i][j]+=lie[i-1][j]+lie[i][j-1]-lie[i-1][j-1];
		}
	}
	for(i=1;i<=Q;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%d\n",
		qz[c][d]-qz[c][b-1]-qz[a-1][d]+qz[a-1][b-1]-
		(ha[c][d-1]-ha[c][b-1]-ha[a-1][d-1]+ha[a-1][b-1])-
		(lie[c-1][d]-lie[c-1][b-1]-lie[a-1][d]+lie[a-1][b-1])
		);
	}
}
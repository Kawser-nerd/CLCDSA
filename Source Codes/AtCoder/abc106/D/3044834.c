#include <stdio.h>

int main()
{
	int n,m,q,i,j,k,a,b,c,d,kari=0;
	int board[501][501]={0};
	int nboard[501][501]={0};
	static int ans[100010];
	scanf("%d %d %d",&n,&m,&q);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&a,&b);
		board[a][b]++;
	}/*
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}*/
	for(i=1;i<=n;i++)
	{
		nboard[i][i]=board[i][i];
		for(j=i+1;j<=n;j++)
		{
			kari=0;
			for(k=i;k<=j;k++)
			{
				kari+=board[k][j];
			}
			nboard[i][j]=nboard[i][j-1]+kari;
		}
	}
	for(i=0;i<q;i++)
	{
		scanf("%d %d",&c,&d);
		ans[i]=nboard[c][d];
	}
	for(i=0;i<q;i++)
	{
		printf("%d\n",ans[i]);
	}
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&m,&q);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&c,&d);
   ^
#include <stdio.h>

#define GET(X,Y) ( (map[X][(Y>>2)] & (1<<(3-(Y&3)))) != 0 )


char map[600][200];

char bm[600][600];
char used[600][600];
 
int down[600][600];

int can[600];


int m,n;char t;int size;
int test,tt;
int find(int size)
{
	int i,j;int x,y;int count=0;char flag;
	for (x=0;x<m;++x)
		for (y=0;y<n;++y)
			if (!used[x][y])
			{
				flag=1;
				for (i=x;i<x+size;++i)
					if (flag)
					for (j=y;j<y+size;++j)
						if (flag)
							if (i<m && j<n && !used[i][j])
							{
								if (bm[x][y]!=((bm[i][j]+i+j-x-y)&1)) 
									flag=0;
							}
							else
								flag=0;
				if (flag)
				{
					++count;
					for (i=x;i<x+size;++i)
						for (j=y;j<y+size;++j)
							used[i][j]=1;
				}
			}
	can[size]=count;
	return 0;

}
int main()
{
	int i,j;int ans;
	scanf("%d",&test);
					for (tt=1;tt<=test;++tt){	
	scanf("%d%d",&m,&n);
	for (i=0;i<m;++i)
	{
		for (j=0;j<(n>>2);++j)
			scanf("%1X",&map[i][j]);
	}
	for (i=0;i<m;++i)
		for (j=0;j<n;++j)
		{
			bm[i][j]=GET(i,j);
			used[i][j]=0;
		}
	size=m>n?m:n;
	for (i=0;i<=530;++i)
		can[i]=0;
	for (i=size;i>0;--i)
		find(i);
	ans=0;
	for (i=530;i>0;--i)
		if (can[i])
			++ans;
	printf("Case #%d: %d\n",tt,ans);
	for (i=530;i>0;--i)
		if (can[i])
			printf("%d %d\n",i,can[i]);
	
					}
}

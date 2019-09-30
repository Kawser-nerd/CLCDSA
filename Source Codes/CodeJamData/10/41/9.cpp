#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<cmath>

using namespace std;

const int maxn = 250;

char a[maxn][maxn];
bool checked[maxn][maxn];
int n,x;
int tmp;

bool check(int x,int y,int X,int Y)
{
	if(X<0 || X>=2*n || Y<0 || Y>=2*n || !isdigit(a[X][Y]))
	{
		return true;
	}
//	checked[X][Y] = true;
	return a[x][y]==a[X][Y];
}

int dist(int x,int y,int X,int Y)
{
	return abs(x-X) + abs(y-Y);
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int ntest;
	scanf("%d",&ntest);
	for(int test=1;test<=ntest;test++)
	{
		fprintf(stderr,"%d\n",test);
		memset(a,0,sizeof(a));
		scanf("%d",&n); gets(a[0]);
		for(int i=0;i<2*n-1;i++)
		{
			gets(a[i]);
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}*/
		int ans = 2147483647;
		for(int i=0;i<2*n;i++)
		{
			for(int j=0;j<2*n;j++)
			{
				memset(checked,false,sizeof(checked));
				bool ok = true;
				for(int x=0;x<2*n;x++)
					for(int y=0;y<2*n;y++)
						if(isdigit(a[x][y]))
						{
							int xx = i*2-x;
							int yy = j*2-y;
							ok &= check(x,y,xx,y);
							ok &= check(x,y,x,yy);
							ok &= check(x,y,xx,yy);
						}
				if(ok)
				{
				//	tmp = max(max(dist(0,n-1,i,j),dist(n-1,0,i,j)),max(dist(n-1,2*n-2,i,j),dist(2*n-2,n-1,i,j)));
					tmp = dist(n-1,n-1,i,j);
					tmp += n;
					tmp = tmp * tmp - n * n;
					if(ans > tmp) ans = tmp;
				}
			}
		}
		printf("Case #%d: %d\n",test,ans);
	}
	return 0;
}

#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;

int best;
int px,py;
int a[20][20];
int m,n;
int neigh[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

void comb()
{
	int d[20][20];
	int i,j,max,xx,yy,k,bx,by;
	memset(d,0,sizeof(d));
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			if ((i!=px)||(j!=py))
			{
				max=-1;
				for (k=0;k<4;k++)
				{
					xx=i+neigh[k][0];
					yy=j+neigh[k][1];
					if ((xx>=0)&&(xx<m)&&(yy>=0)&&(yy<n)&&(a[xx][yy]>max))
					{
						max=a[xx][yy];
						bx=xx;
						by=yy;
					}
				}
				d[bx][by]+=a[i][j];
			}
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
		{
			a[i][j]-=d[i][j];
			if (a[i][j]<0) a[i][j]=0;
		}
}

void search(int x)
{
	int i,j,xx,yy,k,me,sum;
	int tmpa[20][20];
	for (i=0;i<m;i++)
		for (j=0;j<n;j++)
			tmpa[i][j]=a[i][j];
	if (a[px][py]>0)
	{
		if (x>best) best=x;
	}
	else return;
	sum=0;
	for (i=0;i<4;i++)
	{
		xx=px+neigh[i][0];
		yy=py+neigh[i][1];
		if ((xx>=0)&&(xx<m)&&(yy>=0)&&(yy<n)) sum+=a[xx][yy];
	}
	if (sum==0)
	{
		best=2000000000;
		return;
	}
	comb();
	search(x+1);
	for (i=0;i<4;i++)
	{
		for (j=0;j<m;j++)
			for (k=0;k<n;k++)
				a[j][k]=tmpa[j][k];
		xx=px+neigh[i][0];
		yy=py+neigh[i][1];
		if ((xx>=0)&&(xx<m)&&(yy>=0)&&(yy<n)&&(a[xx][yy]>0))
		{
			me=a[px][py];
			comb();
			a[xx][yy]-=me;
			if (a[xx][yy]<0) a[xx][yy]=0;
			search(x+1);
		}
	}
	for (j=0;j<m;j++)
		for (k=0;k<n;k++)
			a[j][k]=tmpa[j][k];
}

int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);

	int i,j,l,t;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d%d",&n,&m,&py,&px);
		px--;py--;
		for (i=0;i<m;i++)
			for (j=0;j<n;j++)
				scanf("%d",&a[i][j]);
		best=0;
		search(0);
		printf("Case #%d: ",l+1);
		if (best==2000000000) printf("forever\n");
		else printf("%d day(s)\n",best);
	}
	return  0;
}
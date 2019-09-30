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

int a1[10][10];
int a2[10][10];
int d[10];
int used[10];
int m,n,b1;

void search(int x)
{
	int i,j,start;
	if (x==m)
	{
		b1=1;
		for (i=0;i<m;i++)
		{
			for (j=0;j<m;j++)
				if (a1[d[i]][d[j]]!=a2[i][j])
				{
					b1=0;break;
				}
			if (b1==0) break;
		}
		if (b1==1)
		{
			i=i;
		}
		return;
	}
	for (i=0;i<n;i++)
		if (used[i]==0)
		{
			d[x]=i;
			used[i]=1;
			search(x+1);
			if (b1==1) return;
			used[i]=0;
		}

}

int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);

	int x,y,l,t,i;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		memset(a1,0,sizeof(a1));
		for (i=0;i<(n-1);i++)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			a1[x][y]=1;
			a1[y][x]=1;
		}
		scanf("%d",&m);
		memset(a2,0,sizeof(a2));
		for (i=0;i<(m-1);i++)
		{
			scanf("%d%d",&x,&y);
			x--;y--;
			a2[x][y]=1;
			a2[y][x]=1;
		}
		b1=0;
		memset(used,0,sizeof(used));
		search(0);
		if (b1==1) printf("Case #%d: YES\n",l+1);
		else printf("Case #%d: NO\n",l+1);
	}
	return  0;
}
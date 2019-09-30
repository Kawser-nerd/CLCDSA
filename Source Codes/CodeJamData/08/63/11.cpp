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

double d[10][40];

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);

	double p,best,tmp1;
	int i,j,k,l,t,m,x,tmp,base;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%lf%d",&m,&p,&x);
		if (x>=1000000)
		{
			printf("Case #%d: %.6lf\n",l+1,1.0);
			continue;
		}
		base=1000000.0/(1<<m);
		memset(d,0,sizeof(d));
		d[m][1<<m]=1;
		for (i=m-1;i>=0;i--)
		{
			for (j=0;j<(1<<m);j++)
			{
				for (k=0;k<=j;k++)
				{
					tmp1=d[i+1][j-k]*(1-p);
					if (j+k>=(1<<m)) tmp=(1<<m);
					else tmp=j+k;
					tmp1+=d[i+1][tmp]*p;
					if (tmp1>d[i][j]) d[i][j]=tmp1;
				}
			}
			d[i][1<<m]=1;
		}
		printf("Case #%d: %.6lf\n",l+1,d[0][x/base]);
	}
	return  0;
}
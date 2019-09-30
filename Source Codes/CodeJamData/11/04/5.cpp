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

int a[2000];
int b[2000];
double d[2000];
double dd[2000][2000][2];

int main()
{
	freopen("D-large.in","r",stdin);
	freopen("D-large.out","w",stdout);
	int i,l,t,cnt,n,j;
	double p;
	memset(dd,0,sizeof(dd));
	d[0]=0;
	d[1]=0;
	dd[1][1][1]=1;
	dd[1][0][0]=1;
	for (i=2;i<=1000;i++)
	{
		d[i]=0;p=1;
		for (j=i-1;j>=0;j--)
		{
			dd[i][j][0]=1.0/i*dd[i-1][j][0]+(double)(i-1)/i*dd[i-1][j-1][1];
			dd[i][j][1]=1.0/i*dd[i-1][j-1][0]+(double)(i-1)/i*dd[i-1][j-1][1];
			d[i]+=dd[i][j][0]*(d[j]+1);
			p-=dd[i][j][0];
		}
		dd[i][i][0]=p;
		dd[i][i][1]=1.0/i*dd[i-1][i-1][0]+(double)(i-1)/i*dd[i-1][i-1][1];
		d[i]=(d[i]+p)/(1-p);
	}
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(b,b+n);
		cnt=0;
		for (i=0;i<n;i++)
			if (b[i]!=a[i]) cnt++;
		printf("Case #%d: %.6lf\n",l+1,d[cnt]);
	}
	return 0;
}


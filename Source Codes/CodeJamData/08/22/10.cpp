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

int bb[2000000];
int pp[2000000];

int gcd(int x,int y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}

void merge(int x,int y)
{
	int px,py,rx,ry,tmp;
	rx=x;ry=y;
	while (pp[rx]!=-1) rx=pp[rx];
	while (pp[ry]!=-1) ry=pp[ry];
	px=x;
	py=y;
	while ((pp[px]!=rx)&&(pp[px]!=-1))
	{
		tmp=pp[px];
		pp[px]=rx;
		px=tmp;
	}
	while ((pp[py]!=ry)&&(pp[py]!=-1))
	{
		tmp=pp[py];
		pp[py]=ry;
		py=tmp;
	}
	if (rx!=ry) pp[rx]=ry;
}

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);

	int ans,l,t;
	_int64 i,j,a,b,p,tmp;
	for (i=0;i<2000000;i++) bb[i]=1;
	for (i=2;i<2000000;i++)
		if (bb[i]==1)
		{
			j=i+i;
			while (j<2000000)
			{
				bb[j]=0;
				j+=i;
			}
		}

	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%lld%lld%lld",&a,&b,&p);
		for (i=0;i<=b-a;i++)
			pp[i]=-1;
		for (i=p;i<=b-a;i++)
			if (bb[i]==1)
			{
				tmp=a/i*i;
				if (tmp<a) tmp+=i;
				for (j=tmp;j+i<=b;j+=i)
				{
					merge(j-a,j+i-a);
				}
			}
		ans=0;
		for (i=0;i<=b-a;i++)
			if (pp[i]==-1) ans++;
		printf("Case #%d: %d\n",l+1,ans);
	}
	return 0;
}


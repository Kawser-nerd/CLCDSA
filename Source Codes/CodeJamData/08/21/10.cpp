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

int x[200000],y[200000];
int lei[9];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	_int64 tmp,ans;
	int i,j,k,l,t,n,a,b,c,d,m;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d%d%d%d%d%d%d%d",&n,&a,&b,&c,&d,&x[0],&y[0],&m);
		for (i=1;i<n;i++)
		{
			tmp=a;
			tmp*=x[i-1];
			tmp+=b;
			tmp%=m;
			x[i]=tmp;
			tmp=c;
			tmp*=y[i-1];
			tmp+=d;
			tmp%=m;
			y[i]=tmp;
		}
		memset(lei,0,sizeof(lei));
		for (i=0;i<n;i++)
		{
			lei[x[i]%3*3+y[i]%3]++;
		}
		ans=0;
		for (i=0;i<9;i++)
			for (j=i;j<9;j++)
				for (k=j;k<9;k++)
					if (((i%3+j%3+k%3)%3==0)&&((i/3+j/3+k/3)%3==0))
					{
						if ((i!=j)&&(j!=k))
						{
							tmp=lei[i];
							tmp*=lei[j];
							tmp*=lei[k];
						}
						else if ((i==j)&&(j==k))
						{
							if (lei[i]>=3)
							{
								tmp=lei[i];
								tmp*=(lei[i]-1);
								tmp*=(lei[i]-2);
								tmp/=6;
							}
							else tmp=0;
						}
						else
						{
							if (i==j)
							{
								if (lei[i]>=2)
								{
									tmp=lei[i];
									tmp*=(lei[i]-1);
									tmp*=lei[k];
									tmp/=2;
								}
								else tmp=0;
							}
							else
							{
								if (lei[j]>=2)
								{
									tmp=lei[i];
									tmp*=lei[j];
									tmp*=(lei[j]-1);
									tmp/=2;
								}
								else tmp=0;
							}
						}
						ans+=tmp;
					}
		printf("Case #%d: %lld\n",l+1,ans);
	}
	return 0;
}


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

int b[1000000];
_int64 prime[100000];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
	int i,j,l,t,tt,ans;
	_int64 n,tmp;
	memset(b,0,sizeof(b));
	tt=0;
	for (i=2;i<1000000;i++)
		if (b[i]==0)
		{
			prime[tt]=i;
			tt++;
			j=i+i;
			while (j<1000000)
			{
				b[j]=1;
				j+=i;
			}
		}
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%lld",&n);
		if (n==1)
		{
			printf("Case #%d: 0\n",l+1);
			continue;
		}
		ans=0;
		for (i=0;i<tt;i++)
		{
			if (prime[i]*prime[i]>n) break;
			tmp=prime[i];
			while (tmp*prime[i]<=n)
			{
				ans++;
				tmp*=prime[i];
			}
		}
		ans++;
		printf("Case #%d: %d\n",l+1,ans);
	}
	return 0;
}


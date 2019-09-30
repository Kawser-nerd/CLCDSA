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

char c[1000];
int a[1000];
char s[1000];

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int i,l,t,tb,to,pb,po,ans,n;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%s",s);
			c[i]=s[0];
			scanf("%d",&a[i]);
		}
		po=1;to=0;pb=1;tb=0;
		for (i=0;i<n;i++)
		{
			if (c[i]=='O')
			{
				to=to+abs(a[i]-po);
				if (tb>to) to=tb;
				to++;
				po=a[i];
			}
			else
			{
				tb=tb+abs(a[i]-pb);
				if (to>tb) tb=to;
				tb++;
				pb=a[i];
			}
		}
		ans=to;
		if (tb>ans) ans=tb;
		printf("Case #%d: %d\n",l+1,ans);
	}
	return 0;
}


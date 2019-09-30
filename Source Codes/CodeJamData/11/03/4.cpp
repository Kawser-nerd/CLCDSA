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

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int i,l,t,tot,min,x,n;
	scanf("%d",&t);
	for (l=0;l<t;l++)
	{
		scanf("%d",&n);
		x=0;tot=0;min=2000000000;
		for (i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			x^=a[i];
			tot+=a[i];
			if (a[i]<min) min=a[i];
		}
		if (x!=0)
			printf("Case #%d: NO\n",l+1);
		else
		{
			printf("Case #%d: %d\n",l+1,tot-min);
		}
	}
	return 0;
}


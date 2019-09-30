#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;

#define SIZE(x) (int((x).size()))
#define rep(i,l,r) for (int i=(l); i<=(r); i++)
#define repd(i,r,l) for (int i=(r); i>=(l); i--)
#define rept(i,c) for (typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

#ifndef ONLINE_JUDGE
#define debug(x) { cerr<<#x<<" = "<<(x)<<endl; }
#else
#define debug(x) {}
#endif

int solved[1000010];

void lemon()
{
	int x; scanf("%d",&x);
	if (solved[x]!=0) 
	{ 
		if (solved[x]==-1) printf("INSOMNIA\n"); else printf("%lld\n",LL(solved[x])*x); 
		return; 
	}
	int h[10]; memset(h,0,sizeof h);
	int c=10;
	rep(i,1,1000000)
	{
		LL y=LL(i)*x;
		while (y)
		{
			if (!h[y%10]) 
			{
				h[y%10]=1; c--;
				if (c==0) { printf("%lld\n",LL(i)*x); solved[x]=i; return; }
			}
			y/=10;
		}
	}
	solved[x]=-1; printf("INSOMNIA\n");
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("A.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}


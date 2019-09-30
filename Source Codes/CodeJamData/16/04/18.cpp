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

void lemon()
{
	int n,m,s; scanf("%d%d%d",&n,&m,&s);
	if (m*s<n)
	{
		printf("IMPOSSIBLE\n"); return;
	}
	int k=n/m; if (n%m!=0) k++;
	int cs=0;
	set<LL> lis;
	rep(i,1,k)
	{
		LL ans=0;
		rep(j,1,m)
		{
			ans=ans*n+cs;
			cs++; if (cs>=n) cs=0;
		}
		if (lis.count(ans)) continue;
		lis.insert(ans);
		printf("%lld ",ans+1);
	}
	printf("\n");
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("D.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}


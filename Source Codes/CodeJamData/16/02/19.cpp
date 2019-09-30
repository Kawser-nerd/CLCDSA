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

char s[10000], t[10000];

void flip(int k)
{
	reverse(t+1,t+k+1);
	rep(i,1,k) if (t[i]=='-') t[i]='+'; else t[i]='-';
}

void lemon()
{
	scanf("%s",s+1); int n=strlen(s+1);
	int m=1; t[m]=s[m];
	rep(i,2,n)
		if (s[i]!=t[m])
			m++, t[m]=s[i];
	
	int ans=0;
	while (m>0)
	{
		if (t[m]=='+')
			m--;
		else
		{
			ans++;
			if (t[1]=='-' && t[m]=='-')
				flip(m);
			else  flip(m-1), m--;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	ios::sync_with_stdio(true);
	#ifndef ONLINE_JUDGE
		freopen("B.in","r",stdin);
	#endif
	int tcase; scanf("%d",&tcase);
	rep(nowcase,1,tcase)
	{
		printf("Case #%d: ",nowcase);
		lemon();
	}
	return 0;
}


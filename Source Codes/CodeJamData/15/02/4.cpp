//azariamuh

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
using namespace std;

int inf = 1000000000;
typedef long long LL;

#define forn(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define reset(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()

int T,n,ans;
int dp[1005][1005];
int data[1005];

int main()
{
	scanf("%d",&T);
	forn(i,0,1000)
	{
		forn(j,0,i) dp[i][j] = 0;
		forn(j,i+1,1000)
		{
			dp[i][j] = dp[i][j-1] + 1;
			forn(k,1,j-1) dp[i][j] = min(dp[i][j],dp[i][j-k] + dp[i][k] + 1);
		}
	}
	forn(cases,1,T)
	{
		scanf("%d",&n);
		ans = inf;
		int x;
		forn(i,1,n)
			scanf("%d",&data[i]);
		forn(i,1,1000)
		{
			int tot = 0;
			forn(j,1,n) tot += dp[i][data[j]];
			ans = min(ans,tot + i);
			//if (i < 20) printf("%d %d\n",i,tot);
		}
		printf("Case #%d: %d\n",cases,ans);
	}
	return 0;
}














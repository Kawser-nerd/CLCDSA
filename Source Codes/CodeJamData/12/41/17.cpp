// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int d[N],l[N],dp[N];
int main()
{
	int t,n,m,cas=0;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&n);
		for ( int i=0; i<n; i++ ) scanf("%d%d",d+i,l+i);
		scanf("%d",&m);
		memset(dp,0,sizeof(dp));
		dp[0]=d[0];
		for ( int i=0; i<n; i++ ) {
			dp[i]=min(dp[i],l[i]);
			for ( int j=i+1; j<n && d[i]+dp[i]>=d[j]; j++ ) {
				dp[j]=max(dp[j],d[j]-d[i]);
			}
		}
		int ok=0;
		for ( int i=0; i<n; i++ ) if ( d[i]+dp[i]>=m ) ok=1;
		printf("Case #%d: %s\n",++cas,ok?"YES":"NO");
	}
	return 0;
}

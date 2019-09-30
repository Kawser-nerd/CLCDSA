// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define N 2010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,x[N],y[N],ts;
vector<int> e[N];
bool tra( int p ) {
	FOR(it,e[p]) if ( !tra(*it) ) return 0;
	return p==++ts;
}
void go( int p, int m ) {
	if ( p==n ) y[p]=1000000000;
	else y[p]=y[x[p]]-m*(x[p]-p);
	FOR(it,e[p]) go(*it,m++);
}
int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d",&n);
		for ( int i=1; i<n; i++ ) scanf("%d",x+i);
		for ( int i=1; i<=n; i++ ) e[i].clear();
		for ( int i=1; i<n; i++ ) e[x[i]].push_back(i);
		printf("Case #%d:",++cas);
		ts=0;
		if ( !tra(n) ) {
			puts(" Impossible");
			continue;
		}
		go(n,0);
		for ( int i=1; i<=n; i++ ) printf(" %d",y[i]);
		puts("");
	}
	return 0;
}

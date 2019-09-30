// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
#define N 1010
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
int n,w,h,id[N],r[N],x[N],y[N];
bool cp( int a, int b ) { return r[a]>r[b]; }
bool chk() {
	int dn=r[id[0]],rt=r[id[0]],ny=0;
	x[id[0]]=y[id[0]]=0;
	for ( int ii=1; ii<n; ii++ ) {
		int i=id[ii];
		if ( rt+r[i]<=w ) {
			x[i]=rt+r[i];
			y[i]=ny;
			rt+=2*r[i];
		} else {
			if ( dn+r[i]<=h ) {
				x[i]=0;
				y[i]=ny=dn+r[i];
				dn+=2*r[i];
				rt=r[i];
			} else {
				return 0;
			}
		}
	}
	return 1;
}
int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while ( t-- ) {
		scanf("%d%d%d",&n,&w,&h);
		for ( int i=0; i<n; i++ ) scanf("%d",r+i);
		for ( int i=0; i<n; i++ ) id[i]=i;
		sort(id,id+n,cp);
		while ( !chk() );//random_shuffle(id,id+n);
		printf("Case #%d:",++cas);
		for ( int i=0; i<n; i++ ) printf(" %d %d",x[i],y[i]);
		puts("");
	}
	return 0;
}

#pragma comment( linker, "/stack:128000000" )
#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>

void prepare( )
{
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
}

#include <cmath>
#include <cassert>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <sstream>
#include <iostream>
#include <deque>

using namespace std;

#define fo(a,b,c) for(a =(b);a<(c);++a)
#define fr(a,b) fo(a,0,(b))
#define fi(a) fr(i,(a))
#define fj(a) fr(j,(a))
#define fk(a) fr(k,(a))
#define all(a) (a).begin(),(a).end()
#define mp make_pair
#define pb push_back
#define sz(a) (int)(a).size()
#define _(a,b) memset((a),(b),sizeof(a))
#define __(a) _((a),0)

typedef long long lint;

const int MAXN = 505;
const int INF = 1000000000;
int n, m;
int a[MAXN];
int d[MAXN][MAXN];

int solve( int id, int n )
{
	if ( n == 2 )
		return 0;
	int &res = d[id][n];
	if ( res >= 0 )
		return res;
	int i;
	res = INF;
	int l = a[id];
	int r = a[id + n - 1];
	for ( i = id + 1; i < id + n - 1; ++ i )
	{
		res = min( res, solve( id, i - id + 1 ) + solve( i, id + n - i ) + r - l - 2 ); 
	}
	return res;
}

int main( )
{
	prepare( );
	int i, j, k;
	int t, tn;
	cin >> tn;
	fr( t, tn )
	{
		printf( "Case #%d: ", t + 1 );
		scanf( "%d %d", &n, &m );
		fi( m )
		{
			scanf( "%d", &a[i + 1] );
		}
		sort( a + 1, a + m + 1 );
		a[0] = 0;
		a[m + 1] = n + 1;
		_( d, -1 );
		printf( "%d\n", solve( 0, m + 2 ) );
	}
	return 0;
}
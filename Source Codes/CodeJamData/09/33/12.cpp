#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

const int MAXN = 110;
const int inf = 1000000000;

vector< int > V;
int dp[ MAXN ][ MAXN ];

int solve( int l, int r ) {
    if( l > r ) return 0;
    if( l+1 == r ) return 0;
    int &ref = dp[ l ][ r ];
    if( ref != -1 ) return ref;
    ref = inf;

    for( int i = l+1; i < r; ++i ) {
        int val = V[r] - V[l] - 2 + solve( l, i ) + solve( i, r );
        if( val < ref ) ref = val;
    }

    return ref;
}

int main( void )
{
    int T; scanf( "%d", &T );

    for( int counter = 0; counter < T; ++counter ) {
        int n, k; scanf( "%d %d", &n, &k );
        V.clear(); V.reserve( k+2 );
        V.push_back( -1 );
        
        for( int i = 0; i < k; ++i ) {
            int x; scanf( "%d", &x ); --x;
            V.push_back( x );
        }
        
        V.push_back( n );
        sort( V.begin(), V.end() );
        memset( dp, -1, sizeof dp );

        int mini = solve( 0, ( int )V.size() - 1 );
        printf( "Case #%d: %d\n", counter + 1, mini );
    }

    return (0-0);
}

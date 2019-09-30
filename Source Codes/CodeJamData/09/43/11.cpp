#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n, k;
int a[100][25];
int g[100][100];

bool above( int *A, int *B ) {
    for( int i = 0; i < k; ++i )
        if( A[i] <= B[i] ) return false;
    return true;
}

int sparen[100], bio[100];

bool dfs( int i ) {
    if( bio[i] ) return false;
    bio[i] = 1;

    for( int j = 0; j < n; ++j ) {
        if( !g[i][j] ) continue;
        if( sparen[j] == -1 || dfs( sparen[j] ) ) {
            sparen[j] = i;
            return true;
        }
    }
    return false;
}

int matching() {
    memset( sparen, -1, sizeof sparen );
    int ret = 0;
    for( int i = 0; i < n; ++i ) {
        memset( bio, 0, sizeof bio );
        if( dfs( i ) ) ++ret;
    }
    return ret;
}

int main( void ) {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; ++tt ) {
        scanf( "%d%d", &n, &k );
        for( int i = 0; i < n; ++i )
            for( int j = 0; j < k; ++j )
                scanf( "%d", &a[i][j] );

        for( int i = 0; i < n; ++i )
            for( int j = 0; j < n; ++j )
                g[i][j] = above( a[i], a[j] );

        printf( "Case #%d: %d\n", tt, n - matching() );
    }
    return 0;
}

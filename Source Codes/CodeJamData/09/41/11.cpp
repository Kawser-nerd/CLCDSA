#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n;
char buff[41];
int a[40];

int main( void ) {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; ++tt ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i ) {
            scanf( "%s", buff );
            for( a[i] = n-1; a[i] > 0 && buff[a[i]] == '0'; --a[i] );
        }

        int ret = 0;

        for( int i = 0, j; i < n; ++i ) {
            for( j = i; a[j] > i; ++j );

            for( ret += j-i; j != i; --j ) swap( a[j], a[j-1] );
        }

        printf( "Case #%d: %d\n", tt, ret );
    }
    return 0;
}

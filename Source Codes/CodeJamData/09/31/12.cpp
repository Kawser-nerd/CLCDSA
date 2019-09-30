#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <map>
#include <vector>
#include <string>

using namespace std;

const int MAXLEN = 100;

map< char, int > mapper;
char S[ MAXLEN ];

int bio[ MAXLEN ];
int A[ MAXLEN ];

int main( void )
{
    int T; scanf( "%d", &T );

    for( int counter = 0; counter < T; ++counter ) {
        int maks = 0;

        mapper.clear();
        memset( bio, 0, sizeof bio );
        scanf( "%s", S ); int len = strlen( S );

        for( int i = 0; i < len; ++i ) {
            if( mapper.count( S[i] ) ) {
                A[i] = mapper[ S[i] ];
                continue;
            }
            
            for( int j = 0; j < MAXLEN; ++j ) {
                if( j == 0 && i == 0 ) continue;
                if( bio[j] ) continue;
                mapper[ S[i] ] = j;
                maks = max( maks, A[i] = j );
                bio[ j ] = true;
                break;
            }
        }

        long long ret = 0;
        for( int i = 0; i < len; ++i ) 
            ret = ret*(maks+1) + A[i];

        printf( "Case #%d: %lld\n", counter + 1, ret );
    }

    return (0-0);
}

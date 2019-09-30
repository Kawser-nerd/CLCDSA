#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

int trie[ 20 ][ 26 ];
int L , D , N;
char inp[ 10000000 ];
string tmp;
string arr[ 6000 ];

int main()
{
    freopen( "F.out" , "w" , stdout );
    freopen( "A-large.in" , "r" , stdin );
    memset( trie , -1 , sizeof trie );
    
    scanf( "%d%d%d\n" ,&L ,&D ,&N );
    
    for( int c = 0 ; c < D ; c++ )
    {
        scanf( "%s" ,inp );
        arr[ c ] = string( inp );
    }
    for( int c = 0 ; c < N ; c++ )
    {
        memset( trie , 0 , sizeof trie );
        scanf( "%s" ,inp );
        int cur = 0;
        for( int c1 = 0 ; c1 < L ; c1++ , cur ++ )
        {
            if( inp[ cur ] >= 'a' && inp[ cur ] <= 'z' )
            {
                trie[ c1 ][ inp[ cur ] - 'a' ] = 1;
            }
            else
            {
                cur ++;
                while( inp[ cur ] >= 'a' && inp[ cur ] <= 'z' )
                {
                    trie[ c1 ][ inp[ cur ] - 'a' ] = 1;
                    cur ++;
                }
            }
        }
        int ret = 0;
        for( int c1 = 0 ; c1 < D ; c1++ )
        {
            for( int c2 = 0 ; c2 < L ; c2++ )
                if( trie[ c2 ][ arr[ c1 ][ c2 ] - 'a' ] == 0 )
                {
                    goto bad;
                }
            ret ++;
            bad:;
        }  
        printf( "Case #%d: %d\n" ,c + 1 , ret );
    }
    return 0;
}

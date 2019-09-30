#include <stdio.h>

int max( int a, int b );
int min( int a, int b );

int main()
{
    int t, n, p, g[ 100 ], ti, i, answer, j, oneCount, twoCount, threeCount;
    scanf( "%d", &t );
    for( ti = 0; ti < t; ti ++ )
    {
        scanf( "%d%d", &n, &p );
        answer = 0;
        for( i = 0; i < n; i ++ )
        {
            scanf( "%d", &g[ i ] );
            g[ i ] %= p;
            if( g[ i ] == 0 )
                answer ++;
        }
        oneCount = twoCount = threeCount = 0;
        for( i = 0; i < n; i ++ )
            if( g[ i ] == 1 )
                oneCount ++;
            else if( g[ i ] == 2 )
                twoCount ++;
            else if( g[ i ] == 3 )
                threeCount ++;
        if( p == 2 )
            answer += oneCount / 2 + oneCount % 2;
        else if( p == 3 )
        {
            answer += ( max(oneCount, twoCount ) - min( oneCount, twoCount ) ) / 3 + min( oneCount, twoCount );
            threeCount = oneCount + twoCount - (( max(oneCount, twoCount ) - min( oneCount, twoCount ) ) / 3 * 3 + min( oneCount, twoCount ) * 2 );
            answer += threeCount > 0 ? 1 : 0;
        }
        else if( p == 4 )
        {
            answer += min( oneCount, threeCount ) + twoCount / 2;
            i = min( oneCount, threeCount ) * 2 + twoCount / 2 * 2;
            oneCount -= min( oneCount, threeCount );
            threeCount -= min( oneCount, threeCount );
            answer += oneCount / 4 + threeCount / 4;
            i += oneCount / 4 * 4 + threeCount / 4 * 4;
            oneCount %= 4;
            threeCount %= 4;
            if( twoCount % 2 )
            {
                if( oneCount / 2 )
                {
                    answer ++;
                    i += 3;
                }
                else if( threeCount / 2 )
                {
                    answer ++;
                    i += 3;
                }
            }
            answer += ( oneCount + twoCount + threeCount - i ) > 0 ? 1 : 0;
        }
        printf( "Case #%d: %d\n", ti + 1, answer );
    }
    return 0;
}

int max( int a, int b )
{
    return a > b ? a : b;
}

int min( int a, int b )
{
    return a < b ? a : b;
}

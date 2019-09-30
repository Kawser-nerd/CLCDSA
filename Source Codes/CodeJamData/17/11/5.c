#include <stdio.h>

int main()
{
    int t, r, c, i, j, ti, k, l;
    char grid[ 50 ][ 50 ], emptyRow[ 50 ];
    scanf( "%d", &t );
    for( ti = 0; ti < t; ti ++ )
    {
        scanf( "%d%d", &r, &c );
        for( i = 0; i < r; i ++ )
            scanf( "%s", grid[ i ] );
        for( i = 0; i < r; i ++ )
            emptyRow[ i ] = 0;
        for( i = 0; i < r; i ++ )
            for( j = 0; j < c; j ++ )
                if( grid[ i ][ j ] == '?' )
                {
                    for( k = j - 1; k >= 0; k -- )
                        if( grid[ i ][ k ] != '?' )
                            break;
                    if( k >= 0 )
                        for( l = k + 1; l <= j; l ++ )
                            grid[ i ][ l ] = grid[ i ][ k ];
                    else
                    {
                        for( k = j + 1; k < c; k ++ )
                            if( grid[ i ][ k ] != '?' )
                                break;
                        if( k < c )
                            for( l = j; l < k; l ++ )
                                grid[ i ][ l ] = grid[ i ][ k ];
                        else
                        {
                            emptyRow[ i ] = 1;
                            break;
                        }
                    }
                }
        for( i = 0; i < r; i ++ )
            if( emptyRow[ i ] )
            {
                for( j = i - 1; j >= 0; j -- )
                    if( ! emptyRow[ j ] )
                        break;
                if( j >= 0 )
                    for( k = j + 1; k <= i; k ++ )
                        for( l = 0; l < c; l ++ )
                            grid[ k ][ l ] = grid[ j ][ l ];
                else
                {
                    for( j = i + 1; j < r; j ++ )
                        if( ! emptyRow[ j ] )
                            break;
                    for( k = i; k < j; k ++ )
                        for( l = 0; l < c; l ++ )
                            grid[ k ][ l ] = grid[ j ][ l ];
                }
            }
        printf( "Case #%d:\n", ti + 1 );
        for( i = 0; i < r; i ++ )
            puts( grid[ i ] );
    }
    return 0;
}

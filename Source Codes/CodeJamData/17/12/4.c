#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long int r[ 50 ], q[ 50 ][ 50 ];
int deleted[ 50 ][ 50 ], p;

int compare( void * a, void * b );
long int getMultiple( long int a, long int b );
int binarySearch( int index, double min, double max );

int main()
{
    int t, n, ti, i, j, count, k;
    long int multiple, multipleTo;
    scanf( "%d", &t );
    for( ti = 0; ti < t; ti ++ )
    {
        scanf( "%d%d", &n, &p );
        count = 0;
        for( i = 0; i < 50; i ++ )
            for( j = 0; j < 50; j ++ )
                deleted[ i ][ j ] = 0;
        for( i = 0; i < n; i ++ )
            scanf( "%ld", &r[ i ] );
        for( i = 0; i < n; i ++ )
        {
            for( j = 0; j < p; j ++ )
                scanf( "%ld", &q[ i ][ j ] );
            qsort( q[ i ], p, sizeof( long int ), compare );
        }
        for( j = 0; j < p; j ++ )
        {
           // multiple = getMultiple( q[ 0 ][ j ], r[ 0 ] );
            multipleTo = floor( ( ( double ) q[ 0 ][ j ] ) / r[ 0 ] / 0.9 );
            for( multiple = ceil( ( ( double ) q[ 0 ][ j ] ) / r[ 0 ] / 1.1 ); multiple <= multipleTo; multiple ++ )
            {
                for( i = 1; i < n; i ++ )
                    if( ! binarySearch( i, 0.9 * multiple * r[ i ], 1.1 * multiple * r[ i ] ) )
                        break;
                if( i == n )
                {
                    count ++;
                    for( i = 0; i < n; i ++ )
                        for( k = 0; k < p; k ++ )
                            if( deleted[ i ][ k ] == -1 )
                                deleted[ i ][ k ] = 1;
                    break;
                }
            }
        }
        printf( "Case #%d: %d\n", ti + 1, count );
    }
    return 0;
}

int compare( void * a, void * b )
{
    return *( ( long int * ) a ) - *( ( long int * ) b );
}

long int getMultiple( long int a, long int b )
{
    double divisor = ( ( double ) a ) / b;
    if( fabs( ceil( divisor ) - divisor ) <= 0.1 * ceil( divisor ) )
        return ceil( divisor );
    if( fabs( floor( divisor ) - divisor ) <= 0.1 * floor( divisor ) )
        return floor( divisor );
    else
        return -1;
}

int binarySearch( int index, double min, double max )
{
    int i;
    for( i = 0; i < p; i ++ )
        if( ( deleted[ index ][ i ] == 0 || deleted[ index ][ i ] == -1 ) && q[ index ][ i ] >= min && q[ index ][ i ] <= max )
        {
            deleted[ index ][ i ] = -1;
            return 1;
        }
    return 0;
}

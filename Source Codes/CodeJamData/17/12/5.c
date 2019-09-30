
// Google Code Jam 2017
// BrainSteel
// Round 1A
// Problem B
// Compiled with MinGW

#define __USE_MINGW_ANSI_STDIO 1

#include "stdio.h"
#include "string.h"
#include "stdint.h"
#include "math.h"
#include "stdlib.h"

typedef struct
{
    uint64_t min;
    uint64_t max;
} kitrange;

int IsValid( kitrange a )
{
    return a.min <= a.max;
}

int cmprange( const void* a, const void* b )
{
    kitrange* arange = (kitrange*)a;
    kitrange* brange = (kitrange*)b;

    int avalid = IsValid( *arange );
    int bvalid = IsValid( *brange );
    if ( avalid && !bvalid )
    {
        return -1;
    }
    else if ( !avalid && bvalid )
    {
        return 1;
    }
    else if ( !avalid && !bvalid )
    {
        return 0;
    }
    else
    {
        if ( arange->min < brange->min )
        {
            return -1;
        }
        else if ( arange->min > brange->min )
        {
            return 1;
        }
        else
        {
            if ( arange->max < brange->max )
            {
                return -1;
            }
            else if ( arange->max > brange->max )
            {
                return 1;
            }
            else return 0;
        }
    }
}

int DoOverlap( kitrange a, kitrange b )
{
    return IsValid( a ) && IsValid( b ) && a.min <= b.max && b.min <= a.max;
}

int main( int argc, char** argv )
{
    uint64_t T;
    scanf( " %llu", &T );
    uint64_t test_case;
    for ( test_case = 0; test_case < T; test_case++ )
    {
        printf( "Case #%llu: ", test_case + 1 );

        uint64_t N, P;
        scanf( " %llu %llu", &N, &P );
        uint64_t rat[N];
        int i;
        for ( i = 0; i < N; i++ )
        {
            scanf( " %llu", &rat[i] );
        }

        uint64_t packages[N][P];
        kitrange ranges[N][P];
        int j;
        for ( i = 0; i < N; i++ )
        {
            for ( j = 0; j < P; j++ )
            {
                scanf( " %llu", &packages[i][j] );

                ranges[i][j].min = ceil( (packages[i][j] / 1.1) / rat[i] );
                if ( ranges[i][j].min == 0 )
                {
                    ranges[i][j].min++;
                }

                ranges[i][j].max = floor( (packages[i][j] / 0.9) / rat[i] );
            }

            qsort( ranges[i], P, sizeof( kitrange ), cmprange );
        }

#if 0
        for ( i = 0; i < N; i++ )
        {
            for (j = 0; j < P; j++ )
            {
                printf( "kit[%d][%d] in [%llu, %llu]\n", i, j, ranges[i][j].min, ranges[i][j].max );
            }
        }
#endif

        uint64_t* start_indices = calloc( N, sizeof(uint64_t) );
        uint64_t* matched_indices = calloc( N, sizeof(uint64_t) );
        int matches_found = 0;
        for ( j = 0; j < P; j++ )
        {
            if ( !IsValid( ranges[0][j] ))
            {
                //printf( "range[0][%d] invalid.\n", j );
                continue;
            }

            int nmatch_found = 1;
            for ( i = 1; i < N; i++ )
            {
                int k;
                for ( k = start_indices[i]; k < P && !DoOverlap( ranges[i][k], ranges[0][j] ); k++ )
                    ;

                if ( k < P && DoOverlap( ranges[i][k], ranges[0][j] ))
                {
                    //printf( "range[0][%d] matches range[%d][%d]\n", j, i, k );
                    matched_indices[i] = k;
                    nmatch_found++;
                }
            }

            if ( nmatch_found == N )
            {
                matches_found++;
                for ( i = 1; i < N; i++ )
                {
                    start_indices[i] = matched_indices[i] + 1;
                }
            }
        }

        free( start_indices );
        free( matched_indices );
        printf( "%d\n", matches_found );
    }

    return 0;
}

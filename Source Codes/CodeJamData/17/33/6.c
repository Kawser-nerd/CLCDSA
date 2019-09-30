
// Google Code Jam 2017
// BrainSteel
// Round 1C
// Problem C
// Compiled with MinGW

#define __USE_MINGW_ANSI_STDIO 1

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdint.h"

int64_t min( int64_t a, int64_t b )
{
    return a < b ? a : b;
}

int64_t max( int64_t a, int64_t b )
{
    return a > b ? a : b;
}

int64_t i, j, k;

int cmpprob( const void* a, const void* b )
{
    double aprob = *(double*)a;
    double bprob = *(double*)b;

    if ( aprob < bprob )
    {
        return -1;
    }
    else if ( aprob > bprob )
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void printProbs( double* P, int N )
{
    printf( "Probabilities: " );
    int iii;
    for ( iii = 0; iii < N; iii++ )
    {
        printf( " %lf", P[iii] );
    }
    printf( "\n" );
}

int main( int argc, char** argv )
{
    uint64_t T;
    scanf( " %llu", &T );
    uint64_t test_case;
    for ( test_case = 0; test_case < T; test_case++ )
    {
        printf( "Case #%llu: ", test_case + 1 );

        int N, K;
        scanf( " %d %d", &N, &K );

        double U;
        scanf( " %lf", &U );

        double P[N];
        for ( i = 0; i < N; i++ )
        {
            scanf( " %lf", &P[i] );
        }

        //printProbs( P, N );
        qsort( P, N, sizeof( double ), cmpprob );
        //printf( "After sort:\n" );
        //printProbs( P, N );

        int done = 0;
        while( !done )
        {
            int at_min = 1;
            for ( i = 1; P[i] == P[0] && i < N; i++ )
            {
                at_min++;
            }

            if ( i == N )
            {
                //printf( "first\n" );
                for ( j = 0; j < N; j++ )
                {
                    P[j] += U / N;
                }
                done = 1;
            }
            else if ( U >= at_min * (P[i] - P[0]) )
            {
                //printf( "second\n" );
                U -= at_min * (P[i] - P[0]);
                for ( j = 0; j < i; j++ )
                {
                    P[j] = P[i];
                }
            }
            else
            {
                //printf( "third\n" );
                for ( j = 0; j < i; j++ )
                {
                    P[j] += U / at_min;
                }
                done = 1;
            }
            //printProbs( P, N );
        }

        //printProbs( P, N );

        double prob = 1;
        for ( i = 0; i < N; i++ )
        {
            prob *= P[i];
        }

        printf( " %.20lf\n", prob );
    }

    return 0;
}

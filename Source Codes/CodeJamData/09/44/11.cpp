#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int n;
double x[3], y[3], r[3];

double min3( double a, double b, double c ) {
    return min( a, min( b, c ) );
}

double solve( int i, int j ) {
    return (sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) ) + r[i]+r[j])/2;
}

int main( void ) {
    int T;
    scanf( "%d", &T );
    for( int tt = 1; tt <= T; ++tt ) {
        scanf( "%d", &n );
        for( int i = 0; i < n; ++i )
            scanf( "%lf%lf%lf", &x[i], &y[i], &r[i] );

        if( n == 1 )
            printf( "Case #%d: %.10lf\n", tt, r[0] );
        if( n == 2 )
            printf( "Case #%d: %.10lf\n", tt, max( r[0], r[1] ) );
        if( n == 3 )
            printf( "Case #%d: %.10lf\n", tt,
                min3(
                    max( solve(0,1), r[2] ),
                    max( solve(0,2), r[1] ),
                    max( solve(1,2), r[0] )
                     ) );
    }
    return 0;
}

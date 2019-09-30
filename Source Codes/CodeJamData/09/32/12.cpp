#include <algorithm>
#include <functional>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <string>

using namespace std;

typedef long double LD;

struct point {
    LD X, Y, Z;

    point() { X = Y = Z = 0; }
    point( LD _X, LD _Y, LD _Z ) : X( _X ), Y( _Y ), Z( _Z ) {}

    void operator += ( const point &B ) { X += B.X; Y += B.Y; Z += B.Z; }
    point operator + ( const point &B ) { point T = *this; T += B; return T; }
    point operator * ( LD r ) { return point( X*r, Y*r, Z*r ); }

    LD val() { return X*X + Y*Y + Z*Z; }
};

point load()
{
    int x, y, z; scanf( "%d %d %d", &x, &y, &z );
    return point( x, y, z );
}

int main( void )
{
    int T; scanf( "%d", &T );

    for( int counter = 0; counter < T; ++counter ) {
        point A, V;
        int n; scanf( "%d", &n );

        for( int i = 0; i < n; ++i ) {
            point T = load(); A += T;
            point M = load(); V += M;
        }

        A = A * (1./n);
        V = V * (1./n);

        LD l = 0, r = 10000 * ( 600 );

        for( int iter = 0; iter < 200; ++iter ) {
            LD m1 = ( l+l+r ) / 3;
            LD m2 = ( l+r+r ) / 3;

            point F1 = A + (V*m1);
            point F2 = A + (V*m2);

            if( F1.val() > F2.val() )
                l = m1;
            else
                r = m2;
        }
        
        point F = A + (V*l);        
        printf( "Case #%d: %.6Lf %.6Lf\n", counter + 1, sqrt( F.val() ), l );
    }

    return (0-0);
}

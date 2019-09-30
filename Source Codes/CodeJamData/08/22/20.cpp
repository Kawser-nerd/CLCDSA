#include "standard.h"

#pragma comment(linker, "/stack:100000000")

ifstream in( "b.in" );
ofstream out( "b.out" );

void main() {
    int ntests;
    in >> ntests;

    vi mark( 1000001, 1 );
    vi primes;

    for ( int i = 2; i < mark.size(); ++i ) if ( mark[i] ) {
        primes.push_back( i );
        for ( int j = 2 * i; j < mark.size(); j += i )
            mark[j] = 0;
    }

    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";

        ll a, b, p;
        in >> a >> b >> p;

        disjoint_set s( b - a + 1 );
        for ( int i = 0; i < primes.size() && primes[i] <= b; ++i ) if ( primes[i] >= p ) {
            int p = primes[i];
            ll t = ( ( a - 1 ) / p + 1 ) * p;
            for ( ll tt = t; tt <= b; tt += p )
                s.merge( t - a, tt - a );
        }

        int res = 0;
        for ( int i = 0; i <= b - a; ++i )
            res += s.parent[i] == i;

        out << res << endl;
    }
}
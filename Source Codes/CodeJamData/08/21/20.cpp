#include "standard.h"

ifstream in( "a.in" );
ofstream out( "a.out" );

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";

        ll n, a, b, c, d, x, y, m;
        in >> n >> a >> b >> c >> d >> x >> y >> m;

        typedef complex< int > point;

        ll cnt[3][3] = {};
        cnt[x % 3][y % 3]++;
        //vector< point > pts;
        //pts.push_back( point( x, y ) );
        for ( int i = 1; i < n; ++i ) {
            x = ( a * x + b ) % m;
            y = ( c * y + d ) % m;
            cnt[x % 3][y % 3]++;
            //pts.push_back( point( x, y ) );
        }

        ll res = 0;
        int xx[] = { 0, 0, 0, 1, 1, 1, 2, 2, 2 };
        int yy[] = { 0, 1, 2, 0, 1, 2, 0, 1, 2 };

        for ( int i = 0; i < 9; ++i ) {
            res += cnt[xx[i]][yy[i]] * ( cnt[xx[i]][yy[i]] - 1 ) * ( cnt[xx[i]][yy[i]] - 2 ) / 6;

            for ( int j = i + 1; j < 9; ++j ) {
                if ( ( 2 * xx[i] + xx[j] ) % 3 == 0 &&
                     ( 2 * yy[i] + yy[j] ) % 3 == 0)
                     res += cnt[xx[i]][yy[i]] * ( cnt[xx[i]][yy[i]] - 1 ) / 2 * cnt[xx[j]][yy[j]];

                if ( ( 2 * xx[j] + xx[i] ) % 3 == 0 &&
                     ( 2 * yy[j] + yy[i] ) % 3 == 0)
                     res += cnt[xx[j]][yy[j]] * ( cnt[xx[j]][yy[j]] - 1 ) / 2 * cnt[xx[i]][yy[i]];

                for ( int k = j + 1; k < 9; ++k ) {
                    if ( ( xx[i] + xx[j] + xx[k] ) % 3 == 0 &&
                        ( yy[i] + yy[j] + yy[k] ) % 3 == 0) {
                        res += cnt[xx[i]][yy[i]] * cnt[xx[j]][yy[j]] * cnt[xx[k]][yy[k]];
                    }
                }
            }
        }

        //ll rres = 0;
        //for ( int i = 0; i < pts.size(); ++i )
        //    for ( int j = i + 1; j < pts.size(); ++j )
        //        for ( int k = j + 1; k < pts.size(); ++k ) {
        //            point pt = pts[i] + pts[j] + pts[k];
        //            if ( real( pt ) % 3 == 0 && imag( pt ) % 3 == 0 )
        //                ++rres;
        //        }

        //assert( rres == res );

        out << res << endl;
    }
}
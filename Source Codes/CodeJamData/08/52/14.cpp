#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#pragma warning( disable : 4244 4267 4018 )
using namespace std; 
typedef vector< int > vi; typedef vector< vector< int > > vvi; typedef vector< string > vs; typedef vector< double > vd;
typedef vector< vd > vvd; typedef long long ll; typedef vector< ll > vll; typedef vector< vll > vvll; typedef pair< int, int > pii;
#define all( v ) (v).begin( ), (v).end( )

struct dbg {
    ostream & dbg_; dbg() : dbg_( cerr ) { dbg_.setf( ios::fixed ); dbg_.precision( 16 ); }
    //ostringstream dbg_;
    ~dbg() { dbg_ << endl; }
    dbg & operator <<( char const * str ) { dbg_ << str << ' '; return *this; }
    template < class T > dbg & operator <<( T const & t ) { dbg_ << t << ' '; return *this; }
    template < class T, class U > dbg & operator <<( pair< T, U > const & p ) { dbg_ << '('; *this << p.first; *this << p.second; dbg_ << ") "; return *this; }
    template < class T > dbg & operator <<( vector< T > const & v ) { print( all( v ) ); return *this; }
    template < class T, int N > dbg & operator <<( T (&v)[N] ) { print( v, v + N ); return *this; }
    template < class Iter > void print( Iter p, Iter q ) { dbg_ << '{'; for ( ; p != q; ++p ) *this << *p; dbg_ << "} "; }
    template < class T > dbg & operator <<( vector< vector< T > > const & v ) { for ( int i = 0; i != v.size(); ++i ) { dbg_ << ( i ? ' ' : '{' ); print( all( v[i] ) ); dbg_ << ( i == v.size() - 1 ? "} " : "\n" ); } return *this; }
    template < class T, int N, int M > dbg & operator <<( T (&v)[N][M] ) { for ( int i = 0; i != N; ++i ) { dbg_ << ( i ? ' ' : '{' ); print( v[i], v[i] + M ); dbg_ << ( i == N - 1 ? "} " : "\n" ); } return *this; }
};

ifstream in( "b.in" );
ofstream out( "b.out" );

int n, m;
vvi v, e;

int code( int y, int x, int dy, int dx ) {
    return ( ( y * m + x ) << 4 ) + ( dy << 2 ) + dx;
}

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        in >> n >> m;
        vvi l( n, m );
        int x0, y0, x1, y1;
        for ( int i = 0; i < n; ++i ) {
            string s;
            in >> s;
            for ( int j = 0; j < m; ++j ) {
                l[i][j] = s[j] == '#';
                if ( s[j] == 'X' ) { y1 = i, x1 = j; }
                if ( s[j] == 'O' ) { y0 = i, x0 = j; }
            }
        }

        int total = n * m * 16;
        v = e = vvi( total );

        for ( int i = 0; i < n; ++i ) for ( int j = 0; j < m; ++j ) if ( !l[i][j] ) {
            for ( int dx1 = 0; dx1 < 4; ++dx1 ) for ( int dy1 = 0; dy1 < 4; ++dy1 ) if ( dx1 != dy1 ) {
                int s1 = code( i, j, dx1, dy1 );
                for ( int dx2 = 0; dx2 < 4; ++dx2 ) for ( int dy2 = 0; dy2 < 4; ++dy2 ) if ( dx2 != dy2 ) {
                    int s2 = code( i, j, dx2, dy2 );
                    v[s1].push_back( s2 );
                    e[s1].push_back( 0 );
                }

                int dx[] = { 0, -1, 0, 1 };
                int dy[] = { 1, 0, -1, 0 };
                for ( int k = 0; k < 4; ++k ) {
                    int ii = i + dx[k], jj = j + dy[k];
                    if ( ii >= 0 && jj >= 0 && ii < n && jj < m && !l[ii][jj] ) {
                        int s2 = code( ii, jj, dx1, dy1 );
                        v[s1].push_back( s2 );
                        e[s1].push_back( 1 );
                    } else if ( k == dx1 ) {
                        int ii = i + dx[dy1], jj = j + dy[dy1];
                        for ( ; ii >= 0 && jj >= 0 && ii < n && jj < m && !l[ii][jj]; ii += dx[dy1], jj += dy[dy1] ) ;
                        ii -= dx[dy1]; jj -= dy[dy1];

                        int s2 = code( ii, jj, dx1, dy1 );
                        v[s1].push_back( s2 );
                        e[s1].push_back( 1 );
                    }
                }
            }
        }

        vi mark( total );
        int inf = 1e6;
        vi d( total, inf );
        int start = code( y0, x0, 0, 1 );
        d[start] = 0;
        for ( ;; ) {
            int k = -1;
            for ( int j = 0; j < total; ++j ) 
                if ( !mark[j] && ( k == -1 || d[j] < d[k] ) )
                    k = j;

            if ( k == -1 )
                break;
            mark[k] = 1;

            for ( int j = 0; j < v[k].size(); ++j ) {
                int to = v[k][j];
                d[to] = min( d[to], d[k] + e[k][j] );
            }
        }

        int fin = code( y1, x1, 0, 1 );
        if ( d[fin] == inf )
            out << "THE CAKE IS A LIE" << endl;
        else
            out << d[fin] << endl;
    }
}
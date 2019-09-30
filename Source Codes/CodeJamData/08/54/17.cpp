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

ifstream in( "d.in" );
ofstream out( "d.out" );

void main() {
    int ntests;
    in >> ntests;
    int mod = 10007;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        int h, w, r;
        in >> h >> w >> r;
        vvi evil( h, w ), cnt( h, w );
        for ( int i = 0; i < r; ++i ) {
            int y, x;
            in >> y >> x;
            evil[y-1][x-1] = 1;
        }
        cnt[0][0] = 1;
        for ( int i = 0; i < h; ++i ) {
            for ( int j = 0; j < w; ++j ) if ( !evil[i][j] ) {
                for ( int dx = -2; dx < 0; ++dx ) for ( int dy = -2; dy < 0; ++dy ) if ( dx != dy ) {
                    if ( i + dx >= 0 && j + dy >= 0 )
                        cnt[i][j] += cnt[i + dx][j + dy];
                }
                cnt[i][j] = ( cnt[i][j] ) % mod;
            }
        }
        out << cnt[h-1][w-1] << endl;
    }
}
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

ifstream in( "a.in" );
ofstream out( "a.out" );

const int nmax = 6500;
char up[nmax][nmax];
char rght[nmax][nmax];
char num[nmax][nmax];
int cnt = nmax / 2;

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        memset( up, 0, sizeof up ); memset( rght, 0, sizeof rght ); memset( num, 0, sizeof num );
        int l;
        in >> l;
        int x = 0, y = 0, xx, yy;
        int dx[] = { -1, 0, 1, 0 };
        int dy[] = { 0, 1, 0, -1 };
        int cur = 1;
        for ( int i = 0; i < l; ++i ) {
            string s;
            int t;
            in >> s >> t;
            for ( int j = 0; j < t; ++j ) {
                for ( int k = 0; k < s.size(); ++k ) {
                    switch ( s[k] ) {
                        case 'F': {
                            xx = x + dx[cur]; yy = y + dy[cur];
                            if ( xx == x ) rght[cnt + min(y, yy)][cnt + x - 1] = 1;
                            if ( yy == y ) up[cnt + y-1][cnt + min(x, xx)] = 1;
                            x = xx, y = yy; break;
                        }
                        case 'L': cur = ( 4 + cur - 1 ) % 4; break;
                        case 'R': cur = ( cur + 1 ) % 4; break;
                    }
                }
            }
        }

        assert( !x && !y );
        for ( int i = 0; i < nmax; ++i ) {
            int last = -1; bool in = false;
            for ( int j = 0; j < nmax; ++j ) {
                if ( rght[i][j] ) {
                    if ( !in && last != -1 ) {
                        for ( int k = last; k <= j; ++k )
                            ++num[i][k];
                    }
                    last = j + 1;
                    in = !in;
                }
            }
            last = -1; in = false;
            for ( int j = 0; j < nmax; ++j ) {
                if ( up[j][i] ) {
                    if ( !in && last != -1 ) {
                        for ( int k = last; k <= j; ++k )
                            ++num[k][i];
                    }
                    last = j + 1;
                    in = !in;
                }
            }
        }

        int res = 0;
        for ( int i = 0; i < nmax; ++i )
            for ( int j = 0; j < nmax; ++j )
                if ( num[i][j] )
                    ++res;

        out << res << endl;
    }
}
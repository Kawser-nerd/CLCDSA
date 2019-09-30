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

ifstream in( "c.in" );
ofstream out( "c.out" );

vvi s;
int n, m;

void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        in >> n >> m;
        s = vvi( n, m );
        for ( int i = 0; i < n; ++i ) {
            string str;
            in >> str;
            for ( int j = 0; j < m; ++j )
                s[i][j] = str[j] == '.';
        }

        vi v, w;
        v = w = vi( 1 << m );

        for ( int i = 0; i < n; ++i ) {
            w = vi( 1 << m );
            for ( int j = 0; j < 1 << m; ++j ) {
                bool b = true;
                int cnt = 0;
                for ( int x = 0; x < m; ++x ) if ( j & ( 1 << x ) ) {
                    ++cnt;
                    if ( !s[i][x] ) b = false;
                    if ( x < m - 1 && ( j & ( 1 << ( x + 1 ) ) ) ) b = false;
                }
                if ( !b ) continue;
                for ( int k = 0; k < 1 << m; ++k ) {
                    bool b = true;
                    for ( int x = 0; x < m; ++ x ) if ( j & ( 1 << x ) ) {
                        if ( x && ( k & ( 1 << ( x - 1 ) ) ) ) b = false;
                        if ( x < m - 1 && ( k & ( 1 << ( x + 1 ) ) ) ) b = false;
                    }
                    if ( b ) 
                        w[j] = max( w[j], v[k] + cnt );
                }
            }
            v.swap( w );
        }

        out << *max_element( all( v ) ) << endl;
    }
}
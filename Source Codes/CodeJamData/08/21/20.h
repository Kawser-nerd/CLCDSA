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
#include <boost/assign.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/utility.hpp>
#pragma warning( disable : 4244 4267 4018 )
using namespace std; using namespace boost; using namespace boost::assign;
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

template < class T1, class T2 > T1 cast( T2 arg ) { stringstream ss; T1 res; ss << arg; ss >> res; return res; }

template < class T > vector< T > split( string const & str )
{ istringstream iss( str ); return vector< T >( istream_iterator< T >( iss ), istream_iterator< T >( ) ); }

template < class T > vector< T > split( vector< string > const & str ) {
    vector< T > v;
    for( size_t i = 0; i < str.size( ); ++i ) {
        vector< T > w = split< T >( str[i] );
        v.insert( v.end( ), all( w ) );
    }
    return v;
}

template < class T > vector< T > split( string const & str, string const & delim ) {
    vector< string > res;
    size_t i = 0;
    for ( ;; ) {
        size_t j = str.find( delim, i );
        if ( j == string::npos ) {
            res.push_back( cast< T >( str.substr( i ) ) );
            return res;
        }

        res.push_back( cast< T >( str.substr( i, j - i ) ) );
        i = j + delim.size( );
    }
}

string replace_substr( string const & text, string const & pattern, string const & str ) {
    string res = text;
    for ( ;; ) {
        string::size_type pos = res.find( pattern );
        if ( pos == string::npos ) break;
        res.replace( pos, pattern.size(), str, 0, str.size() );
    }
    return res;
}

template < class T > string concat( T p, T q, string const & delim ) {
    ostringstream oss;
    while ( p != q ) {
        oss << *p;
        if ( ++p != q )
            oss << delim;
    }
    return oss.str();
}

double const pi = acos( -1. );

template < class T > void make_min( T & a, T const & b ) { if ( a > b ) a = b; }
template < class T > void make_max( T & a, T const & b ) { if ( a < b ) a = b; }

template < class T > T abs( T a ) { return a < 0 ? -a : a; }
template < class T > T sqr( T x ) { return x * x; }
template < class T > bool btw( T x, T a, T b ) { return  ( a <= x && x <= b ) || ( b <= x && x <= a ); }
template < class T > bool btws( T x, T a, T b ) { return  ( a < x && x < b ) || ( b < x && x < a ); }

template < class T > T gcd( T a, T b ) { if ( b == 0 ) return a; else return gcd( b, a % b ); }
template < class T > T lcm( T a, T b ) { return a * b / gcd( a, b ); }

int const dx[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int const dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };

template < class T > struct indexes_cmp {
    indexes_cmp( vector< T > const & v ) : v_( v ) {}
    bool operator()( int a, int b ) const { return v_[a] < v_[b] || ( v_[a] == v_[b] && a < b ); }
    vector< T > const & v_;
};

template < class T >  void sorted_permutation( vector< T > const & v, vector< int > & p ) {
    p.resize( v.size(), 1 );
    for ( int i = 0; i < p.size(); ++i ) p[i] = i;
    sort( all( p ), indexes_cmp< T >( v ) );
}

double const eps = 1e-8;
bool eq( double a, double b ) { return fabs( a - b ) < eps; }
bool lt( double a, double b ) { return a < b && !eq( a, b ); }
bool gt( double a, double b ) { return a > b && !eq( a, b ); }
bool le( double a, double b ) { return !gt( a, b ); }
bool ge( double a, double b ) { return !lt( a, b ); }

typedef complex< double > point;
template < class T > T X( complex< T > const & a ) { return real( a ); }
template < class T > T Y( complex< T > const & a ) { return imag( a ); }
template < class T > T dot( complex< T > const & a, complex< T > const & b ) { return real( conj( a ) * b ); }
template < class T > T cross( complex< T > const & a, complex< T > const & b ) { return imag( conj( a ) * b ); }
template < class T > T proj( complex< T > const & p, complex< T > const & a, complex< T > const & b ) { return dot( p - a, b - a ) / abs( b - a ); }
template < class T > T dist( complex< T > const & p, complex< T > const & a, complex< T > const & b ) { return cross( p - a, b - a ) / abs( b - a ); }
point rotate( point const & a, point const & b, double ang ) { return ( a - b ) * exp( point( 0, ang ) ) + b; }
point reflect( point const & a, point const & p, point const & q ) { point const & s = q - p; return conj( ( a - p ) / s ) * s + p; }

bool isect( point const & a, point const & b, point const & c, point const & d, point & res ) {
    double u = cross( c - a, b - a ), v = cross( d - a, b - a );
    if ( eq( u, v ) ) return false;
    res = ( u * d - v * c ) / ( u - v );
    return true;
}

bool point_on_seg( point const & p, point const & a, point const & b ) {
    return eq( cross( p - a, b - a ), 0 ) && btw( proj( p, a, b ), 0., abs( b - a ) );
}

bool isect_segs( point const & a, point const & b, point const & c, point const & d, point & res ) {
    if ( !isect( a, b, c, d, res ) )
        return false;
    if ( !point_on_seg( res, a, b ) || !point_on_seg( res, c, d ) )
        return false;
    return true;
}

template < class T > struct make_vector_t {
    make_vector_t & operator ()( T t ) { v_.push_back( t ); return *this; }
    operator vector< T >( ) const { return v_; }
    vector< T > v_;
};
template < class T > make_vector_t< T > make_vector( T t ) { make_vector_t< T > v; v( t ); return v; }

template < class T > vector< T > transpose( vector< T > const & t ) {
    vector< T > u( t[0].size(), T( t.size() ) );
    for ( unsigned i = 0; i < t.size(); ++i )
        for ( unsigned j = 0; j < t[i].size(); ++j )
            u[j][i] = t[i][j];
    return u;
}

template < class T > T column( vector< T > const & p, int i ) {
    T res;
    res.resize( p.size() );
    for ( int j = 0; j < p.size(); ++j )
        res[j] = p[j][i];
    return res;
}

template < class T > int index( vector< T > & v, T const & t ) {
    int pos = find( v.begin(), v.end(), t ) - v.begin();
    if ( pos == v.size() ) v.push_back( t );
    return pos;
}

vvi closure( vvi const & g ) {
    int n = g.size();
    vvi c = g;
    for ( int i = 0; i < n; ++i )
        for ( int j = 0; j < n; ++j )
            for ( int k = 0; k < n; ++k )
                c[j][k] |= c[j][i] & c[i][k];

    return c;
}

vd gauss( vvd p ) {
    int n = p.size(), m = p[0].size();
    vi mark( n );
    for ( int i = 0; i < m - 1; ++i ) {
        int k = -1;
        for ( int j = 0; j < n; ++j )
            if ( p[j][i] != 0 && !mark[j] && ( k == -1 || fabs( p[j][i] ) > fabs( p[k][i] ) ) )
                k = j;

        if ( k == -1 )
            continue;

        for ( int j = i + 1; j < m; ++j )
            p[k][j] /= p[k][i];
        p[k][i] = 1;

        mark[k] = 1;
        for ( int j = 0; j < n; ++j ) if ( p[j][i] != 0 && j != k ) {
            for ( int l = i + 1; l < m; ++l )
                p[j][l] -= p[j][i] * p[k][l];
            p[j][i] = 0;
        }
    }

    vd res( m );
    for ( int i = 0; i < n; ++i ) {
        for ( int j = 0; j < m - 1; ++j ) if ( p[i][j] != 0 ) {
            res[j] = p[i][m - 1] / p[i][j];
            break;
        }
    }

    return res;
}

int bit_count( int i ) {
    i = i - ((i >> 1) & 0x55555555 );
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
    i = (i + (i >> 4)) & 0x0f0f0f0f;
    i = i + (i >> 8);
    i = i + (i >> 16);
    return i & 0x3f;
}

template < class T > struct rmq {
    template < class InIter > rmq( InIter p, InIter q ) : v( p, q ) {
        size_t ofs = 1;
        for ( size_t const size = v.size(); ofs < size; ofs <<= 1 ) ;

        v.resize( ofs, numeric_limits< T >::max() );
        tree.resize( ofs << 1 );
        for ( size_t i = 0; i < ofs; ++i ) tree[ ofs + i ] = i;

        for ( size_t i = ofs - 1; i > 0; --i )
            tree[i] = v[ tree[ i << 1 ] ] <= v[ tree[ ( i << 1 ) + 1 ] ]
                      ? tree[ i << 1 ] : tree[ ( i << 1 ) + 1 ];
    }

    size_t operator()( size_t lo, size_t hi ) const {
        size_t const ofs = tree.size() / 2;
        assert( lo <= hi && hi < ofs );
        lo += ofs; hi += ofs;

        size_t idx = tree[ lo ];
        while ( lo > 0 && lo <= hi ) {
            if ( v[ idx ] > v[ tree[ hi ] ] ||
                 ( v[ idx ] == v[ tree[ hi ] ] && idx > tree[hi] ) ) idx = tree[ hi ];
            if ( v[ idx ] > v[ tree[ lo ] ] ||
                 ( v[ idx ] == v[ tree[ lo ] ] && idx > tree[lo] ) ) idx = tree[ lo ];
            hi--; hi >>= 1;
            lo++; lo >>= 1;
        }

        return idx;
    }

    void erase( size_t idx ) {
        v[ idx ] = numeric_limits< T >::max();
        for ( size_t i = ( tree.size() / 2 + idx ) >> 1; i > 0; i >>= 1 ) {
            tree[i] = v[ tree[ i << 1 ] ] <= v[ tree[ ( i << 1 ) + 1 ] ]
                       ? tree[ i << 1 ] : tree[ ( i << 1 ) + 1 ];
        }
    }

    T operator []( size_t idx ) const       { return v[ idx ]; }
    typename vector< T >::iterator begin()  { return v.begin(); }
    typename vector< T >::iterator end()    { return v.end(); }

    vector< T > v;
    vector< size_t > tree;
};

struct counter {
    counter( size_t n ) {
        size_t ofs = 1;
        for ( ; ofs < n; ofs <<= 1 ) ;

        tree.resize( ofs << 1 );
    }

    size_t operator()( size_t lo, size_t hi ) const {
        size_t const ofs = tree.size() / 2;
        lo += ofs; hi += ofs;

        size_t sum = 0;
        while ( lo > 0 && lo <= hi ) {
            if ( ( lo & 1 ) == 1 )
                sum += tree[lo];
            if ( ( hi & 1 ) == 0 )
                sum += tree[hi];
            hi--; hi >>= 1;
            lo++; lo >>= 1;
        }

        return sum;
    }

    void add( size_t idx ) {
        for ( size_t i = tree.size() / 2 + idx; i > 0; i >>= 1 )
            ++tree[i];
    }

    vector< size_t > tree;
};

struct max_matching {
    max_matching( vvi const & c ) : c( c ), left( c.size(), -1 ), right( c[0].size(), -1 ), size( 0 ) {
        for ( bool t = true; t; )  {
            mark = vi( c[0].size() );
            t = false;
            for ( int i = 0, n = c.size(); i < n; ++i ) if ( left[i] == -1 )
                if ( search( i ) )
                    size++, t = true;
        }
    }

    bool search( int k ) {
        for ( int i = 0, n = c[0].size(); i < n; ++i ) if ( c[k][i] && !mark[i] ) {
            mark[i] = true;
            if ( right[i] == -1 || search( right[i] ) )  {
                right[i] = k; left[k] = i;
                return true;
            }
        }

        return false;
    }

    vvi const & c;
    vi mark, left, right;
    int size;
};

struct disjoint_set {
    disjoint_set( int n ) : parent( n ), rank( n, 1 ) {
        for ( int i = 0; i < n; ++i )
            parent[i] = i;
    }

    int get( int i ) {
        if ( parent[i] != i )
            parent[i] = get( parent[i] );
        return parent[i];
    }

    void merge( int i, int j ) {
        int a = get( i ), b = get( j );
        if ( rank[a] < rank[b] ) {
            parent[a] = b;
            rank[b] += rank[a];
        } else {
            parent[b] = a;
            rank[a] += rank[b];
        }
    }

    vi parent, rank;
};

struct kmp {
    kmp( string const & s ) : s( s ), f( s.size() + 1 ) {
        int t = 0;
        for ( int i = 2; i <= s.size(); ++i ) {
            while ( t > 0 && s[i - 1] != s[t] )
                t = f[t];
            if ( s[i - 1] == s[t] )
                ++t;
            f[i] = t;
        }
    }

    int next( int pos, int ch ) {
        while ( pos > 0 && s[pos] != ch )
            pos = f[pos];
        if ( s[pos] == ch )
            ++pos;
        return pos;
    }

    vi match( string const & str ) {
        int t = 0;
        vi res;
        for ( int i = 0; i < str.size(); ++i ) {
            while ( t > 0 && str[i] != s[t] )
                t = f[t];
            if ( str[i] == s[t] )
                ++t;
            if ( t == f.size() - 1 ) {
                res.push_back( i - f.size() + 2 );
                t = f[t];
            }
        }
        return res;
    }

    vi f;
    string s;
};

struct max_flow {
    max_flow( vvi const & c, int s, int t ) : c( c ) {
        n = c.size();
        f = vvi( n, n );

        for ( ;; ) {
            vi prev = bfs( s );
            if ( prev[t] == -1 ) break;

            int p = t;
            int df = 1e+9;
            while ( p != s ) {
                int q = prev[p];
                df = min( df, c[q][p] - f[q][p] );
                p = q;
            }

            p = t;
            while ( p != s ) {
                int q = prev[p];
                f[q][p] += df; f[p][q] -= df;
                p = q;
            }
        }

        flow = 0;
        for ( int i = 0; i < n; ++i )
            flow += f[s][i];
    }

    vi bfs( int s )
    {
        vi prev( n, -1 ), mark( n );

        queue< int > q;
        q.push( s );
        mark[s] = 1;

        while ( !q.empty() ) {
            int v = q.front(); q.pop();

            for ( int i = 0; i < n; ++i ) {
                if ( !mark[i] && f[v][i] < c[v][i] ) {
                    mark[i] = 1;
                    q.push( i );
                    prev[i] = v;
                }
            }
        }

        return prev;
    }

    int n, flow;
    vvi c, f;
};

struct min_cost_max_flow {
    min_cost_max_flow( vvi const & cap, vvi const & c, int s, int t ) : cap( cap ), c( c ) {
        n = cap.size();
        f = vvi( n, n );

        for ( ;; ) {
            vi prev = dijkstra( s );
            if ( prev[t] == -1 ) break;

            int p = t;
            while ( p != s ) {
                int q = prev[p];
                ++f[q][p]; --f[p][q];
                p = q;
            }
        }

        flow = cost = 0;
        for ( int i = 0; i < n; ++i ) {
            flow += f[s][i];
            for ( int j = 0; j < n; ++j )
                if ( f[i][j] > 0 )
                    cost += f[i][j] * c[i][j];
        }
    }

    vi dijkstra( int s )
    {
        int const inf = 1000000000;

        vi d( n, inf ), prev( n, -1 ), mark( n );
        d[s] = 0;

        for ( ;; ) {
            int k = -1;
            for ( int j = 0; j < n; ++j ) {
                if ( !mark[j] && ( k == -1 || d[k] > d[j] ) )
                    k = j;
            }

            if ( k == -1 || d[k] == inf ) break;
            mark[k] = 1;

            for ( int j = 0; j < n; ++j ) if ( cap[k][j] - f[k][j] > 0 ) {
                    if ( d[j] > d[k] + c[k][j] ) {
                        d[j] = d[k] + c[k][j];
                        prev[j] = k;
                    }
                }
        }

        for ( int i = 0; i < n; ++i )
            for ( int j = 0; j < n; ++j )
                c[i][j] = c[i][j] + d[i] - d[j];

        return prev;
    }

    int n, flow, cost;
    vvi cap, c, f;
};

struct suffix_tree {
    suffix_tree( string const & str )
        : s( str )
    {
        int n = 0, pos = 0;
        nodes.push_back( node() );
        for ( int i = 0; i < s.size() - 1; ++i ) {
            int curpos = pos, prevn = n;
            if ( n ) {
                curpos -= nodes[ n ].size();
                n = nodes[ n ].parent;
                if ( n )
                    n = nodes[n].suffix;
                else
                    curpos++;
            }
            else
                curpos = pos = i;

            while ( curpos < pos ) {
                int prev;
                n = find_child( n, s[ curpos ], prev );
                if ( curpos + nodes[ n ].size() > pos ) {
                    n = split( n, pos - curpos, prev );
                    break;
                }
                curpos += nodes[n].size();
            }

            if ( prevn )
                nodes[ prevn ].suffix = n;

            for ( ;; ) {
                int prev;
                int e = find_child( n, s[ pos ], prev );
                if ( e == -1 )
                    break;
                for ( int i = nodes[ e ].l; i < nodes[ e ].r; ++i, ++pos ) {
                    if ( s[ i ] != s[ pos ] ) {
                        n = split( e, i - nodes[ e ].l, prev );
                        goto finish;
                    }
                }
                n = e;
            }

        finish:     nodes.push_back( node( pos, s.size(), n, nodes[n].child ) );
            nodes[ n ].child = nodes.size() - 1;
        }
    }

    int find_child( int n, char ch, int & prev ) {
        int t = nodes[n].child;
        prev = -1;
        while ( t != -1 ) {
            if ( s[ nodes[ t ].l ] == ch )
                return t;
            prev = t;
            t = nodes[t].sibling;
        }
        return -1;
    }

    int split( int n, int len, int prev ) {
        int m = nodes.size();
        nodes.push_back( node( nodes[n].l, nodes[n].l + len, nodes[n].parent, nodes[n].sibling, n ) );
        if ( prev == -1 )
            nodes[ nodes[ n ].parent ].child = m;
        else
            nodes[ prev ].sibling = m;

        nodes[n].l = nodes[n].l + len;
        nodes[n].parent = m;
        nodes[n].sibling = -1;
        return m;
    }

    struct node {
        node( int l = -1, int r = -1, int parent = -1, int sibling = -1, int child = -1 )
            : l( l ), r( r ), parent( parent ), suffix( -1 ), child( child ), sibling( sibling ) {}

        int size() const { return r - l; }

        int l, r, parent, suffix, child, sibling;
    };

    template < class Out >
        Out traverse( int n, string const & prefix, Out out )
    {
        int t = nodes[ n ].child;
        if ( t == -1 ) {
            *out++ = prefix;
            return out;
        }
        while ( t != -1 ) {
            out = traverse( t, prefix + s.substr( nodes[ t ].l, nodes[ t ].size() ), out );
            t = nodes[ t ].sibling;
        }
        return out;
    }

    string s;
    vector< node > nodes;
};

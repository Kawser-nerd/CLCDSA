#include "standard.h"

ifstream in( "c.in" );
ofstream out( "c.out" );

struct cnt {
    cnt( size_t n ) {
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

    size_t find( size_t pos ) const {
        int lo = 0, hi = tree.size() / 2;
        while ( lo < hi ) {
            int m = ( lo + hi ) / 2;
            int p = this->operator ()( lo, m );
            if ( p <= pos ) {
                lo = m + 1; pos -= p;
            } else
                hi = m;
        }

        return lo;
    }

    void add( size_t idx ) {
        for ( size_t i = tree.size() / 2 + idx; i > 0; i >>= 1 )
            ++tree[i];
    }

    void erase( size_t idx ) {
        for ( size_t i = tree.size() / 2 + idx; i > 0; i >>= 1 )
            --tree[i];
    }

    vector< size_t > tree;
};


void main() {
    int ntests;
    in >> ntests;
    for ( int ntest = 1; ntest <= ntests; ++ntest ) {
        out << "Case #" << ntest << ": ";
        int m, n;
        in >> n >> m;
        vi ind( m );
        for ( int i = 0; i < ind.size(); ++i )
            in >> ind[i];

        cnt t( n );
        for ( int i = 0; i < n; ++i )
            t.add( i );
           
        vi res( n );
        int cur = 0;
        for ( int i = 0; i < n; ++i ) {
            int pos = t.find( cur );
            res[pos] = i + 1;
            t.erase( pos );
            if ( i < n - 1 )
                cur = ( cur + i + 1 ) % ( n - i - 1 );
        }

        for ( int i = 0; i < ind.size(); ++i )
            out << res[ind[i] - 1] << ' ';
        out << endl;
    }
}
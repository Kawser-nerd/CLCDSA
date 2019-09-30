#include	<iostream>
#include	<vector>
#include	<sstream>
#include	<iomanip>
#include	<algorithm>

using namespace std;

#define	MaxN 100000

long	A[ MaxN ];
long	B[ MaxN ];
long	C[ MaxN ];
int		P[ MaxN ];
long	F[ MaxN ];
long	S[ MaxN ];
vector< int >	wEdges[ MaxN ];

int
Get( int x ) {
    return ( x == P[ x ] ) ? x : P[ x ] = Get( P[ x ] );
}

void
Main() {
	int	N;	cin >> N;
	int	M;	cin >> M;

	int	wSortedIndex[ MaxN ];
	for ( auto i = 0; i < N; i++ ) {
        cin >> A[ i ] >> B[ i ];
        C[ i ] = max( A[ i ] - B[ i ], long( 0 ) );
        wSortedIndex[ i ] = i;
        P[ i ] = i;
        S[ i ] = B[ i ];
        F[ i ] = C[ i ];
    }
    auto	wRoot = distance( C, max_element( C, C+ N ) );

	for ( auto i = 0; i < M; i++ ) {
		int	wU;	cin >> wU;	wU--;
		int	wV;	cin >> wV;	wV--;
		wEdges[ wU ].emplace_back( wV );
		wEdges[ wV ].emplace_back( wU );
	}
	
    sort( wSortedIndex, wSortedIndex + N, []( int l, int r ) { return C[ l ] < C[ r ]; } );
	
	vector< bool >	wVisited( N, false );

    for ( auto i = 0; i < N; i++ ) {
        int u = wSortedIndex[ i ];
        wVisited[ u ] = true;
        for ( auto v : wEdges[ u ] ) {
        	if ( wVisited[ v ] ) {
				int x = Get( u );
				int	y = Get( v );
				if ( x == y ) continue;
				P[ y ] = x; S[ x ] += S[ y ];
				F[ x ] = min( F[ x ], max( C[ u ] - S[ y ], F[ y ] ) );
            }
        }
    }
    cout << F[ wRoot ] + S[ wRoot ] << endl;
}

int
main() {
	Main();
	return 0;
}
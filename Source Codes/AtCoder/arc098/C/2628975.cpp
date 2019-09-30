#include	<iostream>
#include	<vector>
#include	<sstream>
#include	<iomanip>
using namespace std;

void
Main() {
	int	N;	cin >> N;
	int	K;	cin >> K;
	int	Q;	cin >> Q;

	long	A[ N ];			for ( auto i = 0; i < N; i++ ) cin >> A[ i ];
	long	wSorted[ N ];	for ( auto i = 0; i < N; i++ ) wSorted[ i ] = A[ i ];

	sort( wSorted, wSorted + N );
	long	v = 1e10;

	for ( auto i = 0; i < N; i++ ) {
		vector< long > wCandidate;
		vector< long > wCurrent;
		for ( auto j = 0; j <= N; j++ ) {
			if ( j == N || A[ j ] < A[ i ] ) {
				sort( wCurrent.begin(), wCurrent.end() );
				if ( wCurrent.size() >= K ) wCandidate.insert( wCandidate.end(), wCurrent.begin(), wCurrent.end() - K + 1 );
				wCurrent.clear();
			} else {
				wCurrent.emplace_back( A[ j ] );
			}
		}
		sort( wCandidate.begin(), wCandidate.end() );
		if ( wCandidate.size() >= Q ) v = min( v, wCandidate[ Q - 1 ] - A[ i ] );
	}
	cout << v << endl;
}

int
main() {
	Main();
	return 0;
}
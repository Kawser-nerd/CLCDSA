#include	<iostream>

using namespace std;

void
Main();

int
main() {
	Main();
	return 0;
}

void
Main() {

	int		N;			cin >> N;

	long	A[ N ];		for ( auto i = 0; i < N; i++ ) cin >> A[ i ];

	long	v = 0;
	long	w = 0;
	int		j = 0;

	for ( auto i = 0; i < N; i++ ) {
		while ( j < N && ( w ^ A[ j ] ) == ( w + A[ j ] ) ) {
			w += A[ j ];
			j++;
		}
		v += j - i;
		w -= A[ i ];
	}

	cout << v << endl;
}
#include <iostream>

int main()
{
	int a[ 3 ] = { 0 }, k;
	std::cin >> a[ 0 ] >> a[ 1 ] >> a[ 2 ] >> k;

	int mx = 0;
	int mi = 0;
	for( int i = 0; i < 3; i++ ) {
		if( mx < a[ i ] ) {
			mx = a[ i ];
			mi = i;
		}
	}

	for( int i = 0; i < k; i++ ) {
		a[ mi ] = a[ mi ] * 2;
	}

	std::cout << a[ 0 ] + a[ 1 ] + a[ 2 ] << std::endl;
	return 0;
}
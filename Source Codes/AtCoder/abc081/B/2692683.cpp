#include <iostream>
#include <algorithm>

int ndiv2( int x )
{
	int cnt = 0;
	while( x % 2 == 0 ) {
		x = x / 2;
		cnt += 1;
	}

	return cnt;
}

int main()
{
	int n;
	std::cin >> n;

	int a[ n ];
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[ i ];
		a[ i ] = ndiv2( a[ i ] );
	}

	std::sort( a, a + n );
	std::cout << a[ 0 ] << std::endl;
	return 0;
}
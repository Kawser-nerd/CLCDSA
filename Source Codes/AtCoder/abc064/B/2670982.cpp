#include <iostream>
#include <algorithm>

int main()
{
	int n;
	std::cin >> n;

	int a[ n ];
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[ i ];
	}

	std::sort( a, a + n );
	int dist = 0;
	for( int i = 1; i < n; i++ ) {
		dist += abs( a[ i - 1 ] - a[ i ] );
	}

	std::cout << dist << std::endl;
	return 0;
}
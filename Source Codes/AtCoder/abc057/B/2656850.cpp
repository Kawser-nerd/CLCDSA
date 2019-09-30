#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair< int, int > > s;
	for( int i = 0; i < n; i++ ) {
		int a, b;
		std::cin >> a >> b;
		s.push_back( std::make_pair( a, b ) );
	}

	std::vector<std::pair< int, int > > c;
	for( int i = 0; i < m; i++ ) {
		int a, b;
		std::cin >> a >> b;
		c.push_back( std::make_pair( a, b ) );
	}

	for( int i = 0; i < n; i++ ) {
		int t = 0, min = 0, minidx = 0;
		for( int j = 0; j < m; j++ ) {
			t = abs( s[ i ].first - c[ j ].first )
			+ abs( s[ i ].second - c[ j ].second );
			if( j == 0 ) {
				min = t;
				minidx = 0;
				continue;
			}

			if( t < min ) {
				min = t;
				minidx = j;
			}
		}
		std::cout << minidx + 1 << std::endl;
	}

	return 0;
}
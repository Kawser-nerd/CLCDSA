#include <iostream>

int main()
{
	int n;
	std::cin >> n;

	int a[ n ];
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[ i ];
	}

	bool is2 = false;
	int cnt = 0;
	int i = 0;
	while( cnt < n ) {
		cnt += 1;
		if( a[ i ] == 2 ) {
			is2 = true;
			break;
		}
		i = a[ i ] - 1;
	}

	std::cout << ( is2 ? cnt : -1 ) << std::endl;
	return 0;
}
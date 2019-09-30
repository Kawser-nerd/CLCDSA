#include <iostream>
#include <algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;

	int a[ n ];
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[ i ];
	}

	std::sort( a, a + n );

	int sum = 0;
	for( int i = n - k; i < n; i++ ) {
		sum += a[ i ];
	}

	std::cout << sum << std::endl;
	return 0;
}
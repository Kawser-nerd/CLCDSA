#include <iostream>

typedef long long ll;

int main()
{
	int n;
	std::cin >> n;

	ll a[ 86 ];
	a[ 0 ] = 2;
	a[ 1 ] = 1;
	for( int i = 2; i <= n; i++ ) {
		a[ i ] = a[ i - 1 ] + a[ i - 2 ];
	}

	std::cout << a[ n ] << std::endl;
	return 0;
}
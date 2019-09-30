#include <iostream>
#include <cmath>

int main()
{
	int n;
	std::cin >> n;

	int a[ 100 ];
	float sum = 0;
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[ i ];
		sum = sum + a[ i ];
	}

	int avr = std::round( sum / n );

	int psum = 0;
	for( int i = 0; i < n; i++ ) {
		psum += ( a[ i ] - avr ) * ( a[ i ] - avr );
	}

	std::cout << psum << std::endl;
	return 0;
}
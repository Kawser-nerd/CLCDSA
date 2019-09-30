#include <iostream>
#include <string>
#include <cmath>

int digits( long long n ) {
	int cnt = 0;
	while( n > 0 ) {
		n = n / 10;
		cnt += 1;
	}

	return cnt;
}

int main()
{
	long long n;
	std::cin >> n;

	long long min = digits( n );
	for( long long i = 1; i <= sqrt( n ); i++ ) {
		long long a, b;
		a = i;
		b = n / a;
		if( a * b != n ) {
			continue;
		}
		//std::cout << a << " " << b << std::endl;

		int t = digits( std::max( a, b ) );
		if( i == 1 ) {
			continue;
		}
		if( t < min ) {
			min = t;
		}
	}
	std::cout << min << std::endl;

	return 0;
}
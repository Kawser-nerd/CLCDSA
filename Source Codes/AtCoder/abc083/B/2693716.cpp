#include <iostream>
#include <string>

int main()
{
	int n, a, b;
	std::cin >> n >> a >> b;

	int sum = 0;
	for( int i = 1; i <= n; i++ ) {
		int x = i;
		int s = 0;
		while( x > 0 ) {
			s += x % 10;
			x = x / 10;
		}
		if( a <= s and s <= b ) {
			sum += i;
		}
	}

	std::cout << sum << std::endl;
	return 0;
}
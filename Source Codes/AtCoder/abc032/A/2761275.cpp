#include <iostream>
#include <cmath>

int main( void )
{
	int a, b, n;
	std::cin >> a >> b >> n;

	int ans = 0;
	for( int i = n; i <= 20000 * 2; i++ ) {
		if( i % a == 0 and i % b == 0 ) {
			ans = i;
			break;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	int ans = 0;
	if( a == b ) {
		ans = c;
	}
	if( b == c ) {
		ans = a;
	}
	if( c == a ) {
		ans = b;
	}

	std::cout << ans << std::endl;
	return 0;
}
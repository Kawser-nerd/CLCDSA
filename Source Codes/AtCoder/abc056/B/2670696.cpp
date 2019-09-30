#include <iostream>

int main()
{
	int w, a, b;
	std::cin >> w >> a >> b;

	int ans = 0;
	if( ( a + w ) < b ) {
		ans = b - ( a + w );
	}
	if( ( b + w ) < a ) {
		ans = a - ( b + w );
	}

	std::cout << ans << std::endl;
	return 0;
}
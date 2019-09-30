#include <iostream>
#include <string>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	// ( n * a ) % b == c


	std::string ans = "NO";
	for( int i = 0; i <= b; i++ ) {
		if( ( i * a ) % b == c ) {
			ans = "YES";
			break;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
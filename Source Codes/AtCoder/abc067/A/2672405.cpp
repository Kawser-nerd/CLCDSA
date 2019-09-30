#include <iostream>
#include <string>

int main()
{
	int a, b;
	std::cin >> a >> b;

	int n[] = { a, b, a + b };
	std::string ans = "Impossible";
	for( int i = 0; i < 3; i++ ) {
		if( n[ i ] % 3 == 0 ) {
			ans = "Possible";
			break;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
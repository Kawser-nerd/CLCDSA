#include <iostream>

int main()
{
	char c;
	int cnt = 0;
	while( std::cin >> c ) {
		if( c == 'o' ) {
			cnt += 1;
		}
	}

	std::cout << cnt * 100 + 700 << std::endl;
	return 0;
}
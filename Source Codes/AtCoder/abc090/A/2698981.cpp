#include <iostream>

int main()
{
	for( int i = 0; i < 3; i++ ) {
		for( int j = 0; j < 3; j++ ) {
			char c;
			std::cin >> c;
			if( i == j ) {
				std::cout << c;
			}
		}
	}
	std::cout << std::endl;
	return 0;
}
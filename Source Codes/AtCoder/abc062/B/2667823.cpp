#include <iostream>

int main()
{
	int h, w;
	std::cin >> h >> w;
	for( int i = 0; i < w + 2; i++ ) {
		std::cout << '#';
	}
	std::cout << std::endl;

	for( int i = 0; i < h; i++ ) {
		for( int j = 0; j < w; j++ ) {
			if( j == 0 ) {
				std::cout << '#';
			}

			char a;
			std::cin >> a;
			std::cout << a;

			if( j == w - 1 ) {
				std::cout << '#' << std::endl;
			}
		}
	}

	for( int i = 0; i < w + 2; i++ ) {
		std::cout << '#';
	}
	std::cout << std::endl;

	return 0;
}
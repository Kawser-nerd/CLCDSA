#include <iostream>

int main()
{
	char x, y;
	std::cin >> x >> y;

	char a;
	if( x > y ) {
		a = '>';
	}
	if( x < y ) {
		a = '<';
	}
	if( x == y ) {
		a = '=';
	}

	std::cout << a << std::endl;
	return 0;
}
#include <iostream>

int main()
{
	int x, a, b;
	std::cin >> x >> a >> b;
	x = x - a;
	while( x >= b ) {
		x = x - b;
	}
	std::cout << x << std::endl;
	return 0;
}
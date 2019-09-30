#include <iostream>

int main()
{
	int x, y, z;
	std::cin >> x >> y >> z;

	int a = ( x - z ) / ( y + z );
	std::cout << a << std::endl;
	return 0;
}
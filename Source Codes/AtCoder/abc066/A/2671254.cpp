#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	int min;
	min = std::min( a + b, b + c );
	min = std::min( c + a, min   );

	std::cout << min << std::endl;
	return 0;
}
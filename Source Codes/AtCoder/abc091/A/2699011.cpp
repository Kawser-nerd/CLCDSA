#include <iostream>

int main()
{
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << ( a + b >= c ? "Yes" : "No" ) << std::endl;
	return 0;
}
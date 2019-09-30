#include <iostream>
int main(int argc, char const *argv[])
{
	int a,b;
	std::cin >> a >> b;
	if (a <= b)
	{
		std::cout << a;
		return 0;
	}
	std::cout << a-1;
	return 0;
}
#include <iostream>

int main()
{
	unsigned long R;
	std::cin >> R;

	if ( R < 1200 )
	{
		std::cout << "ABC" << std::endl;
	}
	else if ( R < 2800 )
	{
		std::cout << "ARC" << std::endl;
	}
	else
	{
		std::cout << "AGC" << std::endl;
	}

	return ( 0 );
}
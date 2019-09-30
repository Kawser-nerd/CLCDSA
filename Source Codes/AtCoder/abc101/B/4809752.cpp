#include <iostream>

int main()
{
	unsigned long N;
	std::cin >> N;

	unsigned long S = 0;
	unsigned long tmpN = N;

	for ( ; tmpN > 0; tmpN /= 10 )
	{
		S += tmpN % 10;
	}

	if ( N % S )
	{
		std::cout << "No" << std::endl;
	}
	else
	{
		std::cout << "Yes" << std::endl;
	}

	return ( 0 );
}
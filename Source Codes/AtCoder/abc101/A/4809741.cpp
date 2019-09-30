#include <iostream>
#include <string>

int main()
{
	int value = 0;
	std::string s;

	std::cin >> s;

	for ( int i = 0; i < 4; i++ )
	{
		if ( s[i] == '+' )
		{
			++value;
		}
		else if ( s[i] == '-' )
		{
			--value;
		}
	}

	std::cout << value << std::endl;

	return ( 0 );
}
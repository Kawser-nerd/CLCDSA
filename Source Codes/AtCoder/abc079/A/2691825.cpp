#include <iostream>
#include <string>

int main()
{
	std::string n;
	std::cin >> n;

	int iss = false;
	if( ( n[ 0 ] == n[ 1 ] and n[ 1 ] == n[ 2 ] ) or
			( n[ 1 ] == n[ 2 ] and n[ 2 ] == n[ 3 ] ) ) {
		iss = true;
	}

	std::cout << ( iss ? "Yes" : "No" ) << std::endl;
	return 0;
}
#include <iostream>
#include <string>
#include <cmath>

bool iswstr( std::string s )
{
	bool isw = true;
	int len = ceil( s.size()/2.0 );
	if( false ) {
		std::cout << len << ":" << s << std::endl;
	}
	for( int i = 0; i < len; i++ ) {
		if( s[ i ] != s[ i + len ] ) {
			isw = false;
			break;
		}
	}
	return isw;
}

int main()
{
	std::string s;
	std::cin >> s;

	bool isw = false;
	for( int i = s.size() - 1; i >= 0; i-- ) {
		s = s.substr( 0, i - 1 );
		isw = iswstr( s );
		if( isw ) {
			break;
		}
	}

	std::cout << s.size() << std::endl;
	return 0;
}
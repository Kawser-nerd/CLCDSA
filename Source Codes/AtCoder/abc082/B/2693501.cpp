#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

void strsort( std::string &s, int order ) {
	int x[ s.size() ];

	for( int i = 0; i < s.size(); i++ ) {
		x[ i ] = s[ i ];
	}

	if( order == 0 ) {
		std::sort( x, x + s.size() );
	}
	else {
		std::sort( x, x + s.size(), std::greater<int> () );
	}

	for( int i = 0; i < s.size(); i++ ) {
		s[ i ] = x[ i ];
	}

	return;
}

int main()
{
	std::string s, t;
	std::cin >> s >> t;

	strsort( s, 0 );
	strsort( t, 1 );

	int r = s.compare( t );

	std::cout << ( r < 0 ? "Yes" : "No" ) << std::endl;
	return 0;
}
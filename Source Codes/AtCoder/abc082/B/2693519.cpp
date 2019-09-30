#include <iostream>
#include <algorithm>
#include <string>

int main()
{
	std::string s, t;
	std::cin >> s >> t;

	std::sort( s.begin(), s.end() );
	std::sort( t.begin(), t.end(), std::greater<int> () );

	int r = s.compare( t );
	std::cout << ( r < 0 ? "Yes" : "No" ) << std::endl;
	return 0;
}
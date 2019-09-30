#include <iostream>
#include <string>

int main()
{
	int a, b;
	std::string s;
	std::cin >> a >> b >> s;

	bool isp = true;
	for( int i = 0; i < s.size(); i++ ) {
			if( i == a ) {
				if( s[ i ] != '-' ) {
					isp = false;
					break;
				}
			}
			else if( s[ i ] == '-' ) {
				isp = false;
				break;
			}
	}

	std::cout << ( isp ? "Yes" : "No" ) << std::endl;
	return 0;
}
#include <iostream>
#include <string>

int main()
{
	int n;
	std::cin >> n;

	std::string ans = "Three";
	for( int i = 0; i < n; i++ ) {
		std::string s;
		std::cin >> s;
		if( s == "Y" ) {
			ans = "Four";
			break;
		}
	}

	std::cout << ans << std::endl;
	return 0;
}
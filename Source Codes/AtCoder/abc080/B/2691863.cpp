#include <iostream>
#include <string>

int main()
{
	std::string s;
	std::cin >> s;

	int sum = 0;
	for( int i = 0; i < s.size(); i++ ) {
		sum += s[ i ] - '0';
	}
	
	int n = std::stoi( s );
	std::cout << ( n % sum == 0 ? "Yes" : "No" ) << std::endl;
	return 0;
}
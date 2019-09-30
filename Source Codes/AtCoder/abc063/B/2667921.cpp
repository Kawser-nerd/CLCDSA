#include <iostream>
#include <string>
#include <set>

int main()
{
	std::string str;
	std::cin >> str;
		
	std::set<char> s;
	bool isdup = false;
	for( int i = 0; i < str.size(); i++ ) {
		auto r = s.insert( str[ i ] );
		isdup = !r.second;
		if( isdup ) {
			break;
		}
	}

	std::cout << ( !isdup ? "yes" : "no" ) << std::endl;
	return 0;
}
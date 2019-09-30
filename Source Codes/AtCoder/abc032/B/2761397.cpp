#include <iostream>
#include <string>
#include <set>

int main( void )
{
	std::string s;
	int k;

	std::cin >> s >> k;

	std::set<std::string> st;
	for( int i = 0; i < s.size() - 1; i++ ) {
		std::string t = s.substr( i, k );
		if( t.size() == k ) {
			st.insert( t );
		}
	}

	std::cout << st.size() << std::endl;
	return 0;
}
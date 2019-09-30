#include <iostream>
#include <set>

int main()
{
	int n;
	std::cin >> n;

	int a[ n ];
	for( int i = 0; i < n; i++ ) {
		std::cin >> a[ i ];
	}

	bool is2 = false;
	std::set<int> s;
	for( int i = 0; i < n; i = a[ i ] - 1 ) {
		auto r = s.insert( a[ i ] - 1 );
		if( r.second == false ) {
			is2 = false;
			break;
		}
		if( a[ i ] == 2 ) {
			is2 = true;
			break;
		}
	}

	int size = s.size();
	std::cout << ( is2 ? size : -1 ) << std::endl;
	return 0;
}
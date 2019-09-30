#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	unsigned int N;
	std::vector<unsigned long> v;

	std::cin >> N;

	for ( int i = 0; i < N; i++ )
	{
		unsigned long tmp;
		std::cin >> tmp;
		v.emplace_back( tmp );
	}

	// ??????????
	std::sort( v.begin(), v.end(), []( unsigned long a, unsigned long b ) {
			return ( a > b );
		} );

	// ???????????????
	std::cout << v[0] - v.back() << std::endl;

	return ( 0 );
}
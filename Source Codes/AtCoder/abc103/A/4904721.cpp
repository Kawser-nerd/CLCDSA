#include <iostream>
#include <vector>
#include <algorithm>

int myABS( int a, int b )
{
	return ( a < b ? b - a : a - b );
}

int main()
{
	int A1, A2, A3;
	std::cin >> A1 >> A2 >> A3;

	std::vector<int> v;

	// A1 -> A2 -> A3
	v.emplace_back( myABS( A1, A2 ) + myABS( A2, A3 ) );

	// A1 -> A3 -> A2
	v.emplace_back( myABS( A1, A3 ) + myABS( A2, A3 ) );

	// A2 -> A1 -> A3
	v.emplace_back( myABS( A1, A2 ) + myABS( A1, A3 ) );

	// A2 -> A3 -> A1
	v.emplace_back( myABS( A2, A3 ) + myABS( A1, A3 ) );

	// A3 -> A1 -> A2
	v.emplace_back( myABS( A1, A3 ) + myABS( A1, A2 ) );

	// A3 -> A2 -> A1
	v.emplace_back( myABS( A2, A3 ) + myABS( A1, A2 ) );

	// ?????
	std::sort( v.begin(), v.end(), []( int a, int b ) {
			return( a < b );
		} );

	std::cout << v[0] << std::endl;	//	??????

	return ( 0 );
}
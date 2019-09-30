#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using MyTuple = std::tuple<long long, long long, long long>;
using MyVect = std::vector<MyTuple>;

int main()
{
	int n, m;
	std::cin >> n >> m;
	MyVect v[8];

	for ( int i = 0; i < n; i++ )
	{
		long long x, y, z;
		std::cin >> x >> y >> z;
		v[0].emplace_back( std::make_tuple( x, y, z ) );
	}

	// ??????????????????????8??????vector?????
	v[1] = v[2] = v[3] = v[4] = v[5] = v[6] = v[7] = v[0];

	// 1. ( +, +, + )
	std::sort( v[0].begin(), v[0].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<0>( a ) + std::get<1>( a ) + std::get<2>( a )
				 <
				std::get<0>( b ) + std::get<1>( b ) + std::get<2>( b )
			);
		} );

	// 2. ( +, +, - )
	std::sort( v[1].begin(), v[1].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<0>( a ) + std::get<1>( a ) - std::get<2>( a )
				 <
				std::get<0>( b ) + std::get<1>( b ) - std::get<2>( b )
			);
		} );

	// 3. ( +, -, + )
	std::sort( v[2].begin(), v[2].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<0>( a ) - std::get<1>( a ) + std::get<2>( a )
				 <
				std::get<0>( b ) - std::get<1>( b ) + std::get<2>( b )
			);
		} );

	// 4. ( +, -, - )
	std::sort( v[3].begin(), v[3].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<0>( a ) - std::get<1>( a ) - std::get<2>( a )
				 <
				std::get<0>( b ) - std::get<1>( b ) - std::get<2>( b )
			);
		} );

	// 5. ( -, +, + )
	std::sort( v[4].begin(), v[4].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<1>( a ) + std::get<2>( a ) - std::get<0>( a )
				 <
				std::get<1>( b ) + std::get<2>( b ) - std::get<0>( b )
			);
		} );

	// 6. ( -, +, - )
	std::sort( v[5].begin(), v[5].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<1>( a ) - std::get<2>( a ) - std::get<0>( a )
				 <
				std::get<1>( b ) - std::get<2>( b ) - std::get<0>( b )
			);
		} );

	// 7. ( -, -, + )
	std::sort( v[5].begin(), v[5].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				std::get<2>( a ) - std::get<0>( a ) - std::get<1>( a )
				 <
				std::get<2>( b ) - std::get<0>( b ) - std::get<1>( b )
			);
		} );

	// 8. ( -, -, - )
	std::sort( v[5].begin(), v[5].end(), []( MyTuple a, MyTuple b ) {
			return ( 
				-std::get<0>( a ) - std::get<1>( a ) - std::get<2>( a )
				 <
				-std::get<0>( b ) - std::get<1>( b ) - std::get<2>( b )
			);
		} );

	//	???????????
	long long total = 0;
	for ( int i = 0; i < 8; i++ )
	{
		long long tmp;

		long long t1 = 0, t2 = 0, t3 = 0;
		for ( int j = 0; j < m; j++ )		//	m???
		{
			t1 += std::get<0>( v[i][j] );
			t2 += std::get<1>( v[i][j] );
			t3 += std::get<2>( v[i][j] );
		}

		auto myAbs = []( long long x ) {
				return ( x < 0 ? -x : x );
		};

		auto tmpAbs = myAbs( t1 ) + myAbs( t2 ) + myAbs( t3 );
		if ( tmpAbs > total )
		{
			// ????????????
			total = tmpAbs;
		}
	}

	std::cout << total << std::endl;

	return ( 0 );
}
#include <iostream>
#include <cmath>

typedef long long int ll;

int main( void )
{
	int n;
	std::cin >> n;

	int mincnt = std::pow( 10, 9 );;
	for( int i = 0; i < n; i++ ) {
		ll a;
		std::cin >> a;

		int cnt = 0;
		for( int i = 0; i < std::pow( 10, 9 ); i++ ) {
			if( a % 2 != 0 ) {
				break;
			}
			a = a / 2;
			if( a % 2 != 0 ) {
				cnt = i + 1;
				break;
			}
		}

		mincnt = std::min( mincnt, cnt );
	}

	std::cout << mincnt << std::endl;
	return 0;
}
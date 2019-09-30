#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

void move(
	std::vector<std::pair<int, int>> &a,		/* answer */
	int sx, int sy,	/* start x, y */
	int tx, int ty,	/* goal  x, y */
	int d						/* direction 1 or -1 */
) {
	int mx = sx, my = ty;
	for( int y = sy; y != my + d; y += d ) {
		a.push_back( std::make_pair( sx, y ) );
	}
	for( int x = mx; x != tx + d; x += d ) {
		a.push_back( std::make_pair( x, my ) );
	}
}

void decode(
	std::vector<std::pair<int, int>> &a
)
{
	std::pair<int, int> p;
	a.erase( std::unique( a.begin(), a.end() ), a.end() );

	for( int i = 1; i < a.size(); i++ ) {
		int x1 = a[ i - 1 ].first,
				y1 = a[ i - 1 ].second,
				x2 = a[ i ].first,
				y2 = a[ i ].second;

		std::string ans = "";
		if( x1 == x2 and y1 < y2 ) {
			ans = "U";
		}
		if( x1 == x2 and y1 > y2 ) {
			ans = "D";
		}
		if( x1 < x2 and y1 == y2 ) {
			ans = "R";
		}
		if( x1 > x2 and y1 == y2 ) {
			ans = "L";
		}
		std::cout << ans;
	}
	std::cout << std::endl;
	return;
}

int main()
{
	int sx, sy, tx, ty;
	std::cin >> sx >> sy >> tx >> ty;

	std::vector<std::pair<int, int>> a;

	move( a, sx, sy, tx, ty,  1 );
	move( a, tx, ty, sx, sy, -1 );

	move( a, sx, sy, sx - 1, sy, -1 );
	move( a, sx - 1, sy, tx, ty + 1, 1 );
	move( a, tx, ty + 1, tx, ty, -1 );

	move( a, tx, ty, tx + 1, ty, 1 );
	move( a, tx + 1, ty, sx, sy - 1, -1 );
	move( a, sx, sy - 1, sx, sy, 1 );

	decode( a );
	
	return 0;
}
#include <iostream>
#include <vector>

int belong( std::vector<int> g, int a, int b )
{
	int cnt = 0;
	for( int i = 0; g[ i ] != 0; i++ ) {
		if( g[ i ] == a or g[ i ] == b ) {
			cnt += 1;
		}
	}
	return cnt;
}

int main()
{
	std::vector<int> g[] = {
		{ 1, 3, 5, 7, 8, 10, 12, 0 },
		{ 4, 6, 9, 11, 0 },
		{ 2, 0 },
	};

	int a, b;
	std::cin >> a >> b;

	bool isbel = false;
	for( int i = 0; i < 3; i++ ) {
		if( belong( g[ i ], a, b ) == 2 ) {
			isbel = true;
			break;
		}
	}

	std::cout << ( isbel ? "Yes" : "No" ) << std::endl;
	return 0;
}
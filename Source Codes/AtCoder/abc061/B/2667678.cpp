#include <iostream>
#include <cstring>
 
int main()
{
	int n, m;
	std::cin >> n >> m;
 
	int r[ n ];
	std::memset( r, 0, sizeof( r ) );
 
	for( int i = 0; i < m; i++ ) {
		int a, b;
		std::cin >> a >> b;
 
		r[ a - 1 ] += 1;
		r[ b - 1 ] += 1;
	}
 
	for( int i = 0; i < n; i++ ) {
		std::cout << r[ i ] << std::endl;
	}
	
	return 0;
}
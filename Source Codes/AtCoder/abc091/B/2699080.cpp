#include <iostream>
#include <string>

void read( std::string s[], int n )
{
	for( int i = 0; i < n; i++ ) {
		std::cin >> s[ i ];
	}
	return;
}

int main()
{
	int n, m;

	std::cin >> n;
	std::string s[ 100 ];
	read( s, n );

	std::cin >> m;
	std::string t[ 100 ];
	read( t, m );

	int maxcnt = 0;
	for( int i = 0; i < n; i++ ) {
		std::string b = s[ i ];
		int cnt = 0;
		for( int j = 0; j < n; j++ ) {
			if( b == s[ j ] ) {
				cnt += 1;
			}
		}
		for( int k = 0; k < m; k++ ) {
			if( b == t[ k ] ) {
				cnt -= 1;
			}
		}
		maxcnt = std::max( maxcnt, cnt );
	}

	std::cout << maxcnt << std::endl;
	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int x[128] , y[128];
char c[128];

vector < pair < int , int > > f;

void read() {
	int i;
	
	scanf ( "%d\n" , &n );
	for (i = 1; i <= n; i++) {
		scanf ( "%d %d %c\n" , &x[i] , &y[i] , &c[i] );
	}
}

inline int dist ( pair < int , int > a ) {
	return abs ( a.first ) + abs ( a.second );
}

int cmp ( pair < int , int > a , pair < int , int > b ) {
	if ( dist ( a ) != dist ( b ) ) {
		return dist ( a ) < dist ( b );
	}
	
	if ( a.first != b.first ) return a.first > b.first;
	return a.second > b.second;
}

void solve() {
	int i , j;
	
	f.clear();
	for (i = -500; i <= 500; i++) {
		for (j = -500; j <= 500; j++) {
			f.push_back ( make_pair ( i , j ) );
		}
	}
	
	sort ( f.begin() , f.end() , cmp );
	
	for (i = 0; i < (int)f.size(); i++) {
		int can = 1;
		
		for (j = 1; j <= n; j++) {
			if ( max ( abs ( f[i].first - x[j] ) , abs ( f[i].second - y[j] ) ) & 1 ) {
				if ( c[j] == '.' ) {
					can = 0;
				}
			} else {
				if ( c[j] == '#' ) {
					can = 0;
				}
			}
		}
		
		if ( can ) {
			printf ( "%d %d\n" , f[i].first , f[i].second );
			return ;
		}
	}
	
	printf ( "Too damaged\n" );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
	}
	
	return 0;
}

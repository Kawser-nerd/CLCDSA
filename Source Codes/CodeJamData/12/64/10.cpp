#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n , m;
int a[16] , b[16];
long long ans;
int best[16];

void read() {
	int i;
	
	scanf ( "%d%d" , &n , &m );
	for (i = 1; i <= n; i++) {
		scanf ( "%d%d" , &a[i] , &b[i] );
	}
}

void go ( long long x , long long y , int left ) {
	if ( x * x + y * y > ans ) ans = x * x + y * y;
// 	if ( x * x + y * y < best[left] ) return ;
// 	best[left] = x * x + y * y;
	
	if ( !left ) return ;
	
	int i;
	long long x1 , y1;
	vector < pair < long long , pair < long long , long long > > > s;
	
	for (i = 1; i <= n; i++) {
		x1 = a[i] + (b[i] - y);
		y1 = b[i] - (a[i] - x);
		s.push_back ( make_pair ( x1 * x1 + y1 * y1 , make_pair ( x1 , y1 ) ) );
	}
	
	sort ( s.rbegin() , s.rend() );
	int lim = 4;
	if ( m - left <= 1 ) lim = (int)s.size();
	for (i = 0; i < min ( lim , (int)s.size() ); i++) {
		go ( s[i].second.first , s[i].second.second , left - 1 );
	}
}

void solve() {
	ans = 0;
	
	memset ( best , 0 , sizeof best );
	
	go ( 0 , 0 , m );
	
	printf ( "%.9lf\n" , sqrt ( (double)ans ) );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
		
		fflush ( stdout );
	}
	
	return 0;
}

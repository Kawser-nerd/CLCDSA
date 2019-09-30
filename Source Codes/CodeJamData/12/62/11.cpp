#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n , m;
double prob[10005];
int c[10005];

vector < double > all;
double dp1[1 << 20][2];
double dp2[1 << 20][2];

void read() {
	int i , x , y;
	
	scanf ( "%d%d" , &n , &m );
	for (i = 1; i <= n; i++) {
		scanf ( "%d/%d %d" , &x , &y , &c[i] );
		prob[i] = (double)x / (double)y;
		
// 		printf ( "%lf\n" , prob[i] );
	}
}
/*
void go ( int x , int y , double prob ) {
	if ( x == m ) {
		return;
	}
	
	if ( y == 0 ) {
		go ( x + 1 , 1 , prob * (1 - cur[x]) );
		go ( x + 1 , 0 , prob * cur[x] );
	} else {
		go ( x + 1 , 1 , prob * (1 - cur[x]) );
		now += prob * cur[x];
	}
}
*/
void solve() {
	int i;
	double ans = 1 , now;
	
	all.clear();
	for (i = 1; i <= n; i++) {
		while ( c[i] -- ) {
			all.push_back ( prob[i] );
		}
	}
	
	sort ( all.rbegin() , all.rend() );
	
	dp1[0][0] = all[0];
	dp1[0][1] = (1 - all[0]);
	for (i = 1; i < (int)all.size(); i++) {
		dp1[i][0] = dp1[i - 1][0] * all[i];
		dp1[i][1] = dp1[i - 1][0] * (1 - all[i]) + dp1[i - 1][1] * (1 - all[i] );
	}
	
	dp2[(int)all.size()][0] = dp2[(int)all.size()][1] = 1;
	for (i = (int)all.size() - 1; i >= 0; i--) {
		dp2[i][0] = dp2[i + 1][0] * all[i] + dp2[i + 1][1] * (1 - all[i]);
		dp2[i][1] = dp2[i + 1][1] * (1 - all[i]);
	}/*
	
	for (i = 0; i < (int)all.size(); i++) {
		printf ( "(%lf,%lf) " , dp1[i][0] , dp1[i][1] );
	}printf ( "\n" );
	
	for (i = 0; i < (int)all.size(); i++) {
		printf ( "(%lf,%lf) " , dp2[i][0] , dp2[i][1] );
	}printf ( "\n" );
	*/
	for (i = 0; i <= m; i++) {
		/*
		for (j = 0; j < i; j++) {
// 			cur.push_back ( all[j] );
		}
		*/
// 		for (j = 0; j < m - i; j++) {
// 			cur.push_back ( all[(int)all.size() - j - 1] );
// 		}
	/*	
		sort ( cur.rbegin() , cur.rend() );
		
		now = 0;
		go ( 0 , 0 , 1 );
		*/
	
		now = 0;
	
		if ( i == 0 ) {
			now = dp2[ (int)all.size() - m ][0];
		} else {
			if ( i == m ) {
				now = dp1[i - 1][0] + dp1[i - 1][1];
			} else {
				now = (dp1[i - 1][0] + dp1[i - 1][1]) * dp2[ (int)all.size() - m + i ][1];
				now += dp1[i - 1][0] * dp2[ (int)all.size() - m + i + 1][0] * all[ (int)all.size() - m + i];
			}
		}
		
		now = 1 - now;
		
// 		printf ( "-- %lf\n" , now );
		
		if ( now < ans ) ans = now;
	}
	
	printf ( "%.9lf\n" , ans );
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

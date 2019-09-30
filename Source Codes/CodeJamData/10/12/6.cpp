#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long INF = (1 << 30) - 5;

int n , del , ins , dif;
int a[128];
long long dp[2][256];

void read() {
	int i;
	
	scanf ( "%d%d%d%d" , &del , &ins , &dif , &n );
	for (i = 1; i <= n; i++)
		scanf ( "%d" , &a[i] );
}

int cost ( int x , int y ) {
	if ( x > y ) return cost ( y , x );
	if ( x == y ) return 0;
	if ( dif == 0 ) return INF;
	return ((y - x - 1) / dif) * ins;
}

void solve() {
	long long ans = INF;
	int i , j , k;
	
	for (i = 0; i < 2; i++)
		for (j = 0; j < 256; j++)
			dp[i][j] = INF;
	
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 256; j++)
			dp[1][j] = (i - 1) * del + abs ( a[i] - j );
		
		for (j = 0; j < 256; j++)
			dp[1][j] = min ( dp[1][j] , dp[0][j] + del );
		
		for (j = 0; j < 256; j++)
			for (k = 0; k < 256; k++)
				dp[1][k] = min ( dp[1][k] , dp[0][j] + abs ( a[i] - k ) + cost ( j , k ) );
			
		for (j = 0; j < 256; j++) {
			dp[0][j] = dp[1][j];
			dp[1][j] = INF;
		}
	}
	
	ans = del * n;
	for (j = 0; j < 256; j++) 
		ans = min ( ans , dp[0][j] );
	
	printf ( "%lld\n" , ans );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	for (i = 1; i <= cases; i++) {
		printf ( "Case #%d: " , i );
		
		read();
		solve();
	}
	
	return 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 128;

int n;
int x[MAXN], y[MAXN], m[MAXN];

int dp[MAXN][MAXN];

void read() {
	int i;
	
	scanf ( "%d" , &n );
	for (i = 1; i <= n; i++) {
		scanf ( "%d%d%d" , &x[i] , &y[i] , &m[i] );
	}
}

void solve() {
	int i , j , k;
	int dst , tim;
	int ans = 0;
	
	memset ( dp , -1 , sizeof dp );
	
	for (i = 1; i <= n; i++) {
		if ( max ( abs ( x[i] ) , abs ( y[i] ) ) * 100 <= m[i] + 1000 ) {
			dp[i][1] = max ( max ( abs ( x[i] ) , abs ( y[i] ) ) * 100 , m[i] );
			ans = 1;
		}
	}
	
	for (i = 1; i < n; i++) {
		for (j = 1; j <= n; j++) {
			if ( dp[j][i] == -1 ) continue;
			
// 			printf ( "be at %d   get %d   at time %d\n" , j , i , dp[j][i] );
			
			for (k = 1; k <= n; k++) {
				if ( j != k ) {
					tim = dp[j][i] + 750;	
					dst = max ( abs ( x[j] - x[k] ) , abs ( y[j] - y[k] ) ) * 100;
					
					if ( dp[j][i] + dst > tim ) {
						tim = dp[j][i] + dst;
					}
					
					if ( tim > m[k] + 1000 ) continue;
					
					if ( tim < m[k] ) tim = m[k];
					
					if ( dp[k][i + 1] == -1 || dp[k][i + 1] > tim ) {
// 						printf ( "put (%d,%d)  from  (%d,%d)      %d\n" , k , i + 1 , j , i , tim );
						dp[k][i + 1] = tim;
						ans = i + 1;
					}
				}
			}
		}
	}
	
	printf ( "%d\n" , ans );
}

int main() {
	int i , cases;
	
	scanf ( "%d" , &cases );
	
	for (i = 1; i <= cases; i++) {
		read();
		printf ( "Case #%d: " , i );
		solve();
		
// 		break;
	}
	
	return 0;
}

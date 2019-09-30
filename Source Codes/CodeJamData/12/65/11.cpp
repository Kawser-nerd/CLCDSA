#include <cstdio>
#include <cstring>

int n;
int l[16] , r[16];
int u[1 << 10][16];

void read() {
	int i;
	
	scanf ( "%d" , &n );
	for (i = 1; i < n; i++) {
		scanf ( "%d%d" , &l[i] , &r[i] );
	}
}

void solve() {
	memset ( u , 0 , sizeof u );
	
	int mask = 0;
	int cur = 1;
	int next;
	int ans = 0;
	
	u[mask][cur] = 1;
	
	while ( 1 ) {
		if ( (mask & (1 << (cur - 1))) ) {
			next = r[cur];
// 			printf ( "right\n" );
		} else {
			next = l[cur];
// 			printf ( "left\n" );
		}
		
		mask ^= (1 << (cur - 1));
		
		if ( u[mask][next] ) {
			printf ( "Infinity\n" );
			return ;
		}
		u[mask][next] = 1;
		
		++ ans;
		if ( next == n ) {
			break;
		}
		
		cur = next;
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
	}
	
	return 0;
}

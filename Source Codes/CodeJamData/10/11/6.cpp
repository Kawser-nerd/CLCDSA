#include <cstdio>
#include <cstring>

int n , k;
char b[64][64] , a[64][64];
int have[256];

void read() {
	int i;
	
	scanf ( "%d%d" , &n , &k );
	for (i = 0; i < n; i++)
		scanf ( "%s" , b[i] );
}

void solve() {
	int i , j , d;
	
	memset ( have , 0 , sizeof have );
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) 
			a[i][j] = b[n - j - 1][i];
		
		a[i][j] = '\0';
	}
	
	for (j = 0; j < n; j++) {
		d = n - 1;
		
		for (i = n - 1; i >= 0; i--) {
			if ( a[i][j] != '.' )
				a[d --][j] = a[i][j];
		}
		
		for (i = 0; i <= d; i++)
			a[i][j] = '.';
	}
	
//	for (i = 0; i < n; i++)
//		printf ( "%s\n" , a[i] );
	
	for (i = 0; i < n; i++) 
		for (j = 0; j < n; j++) {
			for (d = 0; d < k && d + i < n; d++) 
				if ( a[i + d][j] != a[i][j] )
					break;
			if ( d == k ) have[ a[i][j] ] = 1;
			
			for (d = 0; d < k && d + j < n; d++) 
				if ( a[i][j + d] != a[i][j] )
					break;
			if ( d == k ) have[ a[i][j] ] = 1;
			
			for (d = 0; d < k && d + i < n && j - d >= 0; d++) 
				if ( a[i + d][j - d] != a[i][j] )
					break;
			if ( d == k ) have[ a[i][j] ] = 1;
			
			for (d = 0; d < k && d + i < n && j + d < n; d++) 
				if ( a[i + d][j + d] != a[i][j] )
					break;
			if ( d == k ) have[ a[i][j] ] = 1;
		}
		
	if ( have['B'] ) {
		if ( have['R'] )
			printf ( "Both\n" );
		else
			printf ( "Blue\n" );
	} else
		if ( have['R'] )
			printf ( "Red\n" );
		else
			printf ( "Neither\n" );
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

#include <stdio.h>
#include <string.h>
#include <assert.h>

int main( void ) {
	int T;
	scanf("%i", &T);
	
	for( int t = 1; t <= T; t++ ) {
		long long m;
		int n;
		scanf("%i %lld", &n, &m);
		
		long long f[n+1];
		
		f[1] = 1;
		for( int i = 2; i <= n; i++ ) {
			f[i] = 0;
			for( int j = 1; j < i; j++ ) {
				f[i] += f[j];
			}			
		}
				
		printf("Case #%i: ", t);
		
		if( f[n] >= m ) {
			puts("POSSIBLE");
			
			int g[55][55];
			memset(g, 0, sizeof(g));
			
			for( int i = 1; i < n; i++ ) {
				for( int j = i+1; j < n; j++ ) {
					g[i][j] = 1;
				}
			}
			
			if( f[n] == m ) {
				for( int i = 1; i < n; i++ ) {
					for( int j = i+1; j <= n; j++ ) {
						g[i][j] = 1;
					}
				}
			} else {
				for( int i = 0; i <= 50; i++ ) {
					int b = (m >> i) & 01;
					if( b ) {
						g[i+2][n] = 1;
					}
				}
			}
			
			for( int i = 1; i <= n; i++ ) {
				for( int j = 1; j <= n; j++ ) {
					printf("%i", g[i][j]);
				}
				puts("");
			}	
			
			long long f[55] = {0};
			
			f[1] = 1;
			for( int i = 1; i < n; i++ ) {
				for( int j = i + 1; j <= n; j++ ) {
					if( g[i][j] ) f[j] += f[i];
				}
			}
			
			assert(f[n] == m);
			
		} else {
			puts("IMPOSSIBLE");
		}
	}
	
	return 0;
}
#include <stdio.h>
#include <stdbool.h>

#include <assert.h>

int main( void ) {
	int T;
	scanf("%i", &T);
	
	for( int t = 1; t <= T; t++ ) {
		int n;
		scanf("%i", &n);
		
		int tot = 0;
		
		int P[n+1];
		for( int i = 0; i < n; i++ ) {
			scanf("%i", &P[i]);
			tot += P[i];
		}
		
		printf("Case #%i: ", t);
		while( tot > 0 ) {
			bool one = false;
			for( int i = 0; i < n; i++ ) {
				if( P[i] * 2 > tot - 1 ) {
					putchar('A'+i);
					tot--, P[i]--;
					one = true;
					break;
				}
			}
			
			for( int i = 0; i < n; i++ ) {
				if( P[i] * 2 > tot - 1 ) {
					putchar('A'+i);
					tot--, P[i]--;
					one = true;
					break;
				}
			}
			
			if( one == false ) {
				int max = 0, idx = -1;
				for( int i = 0; i < n; i++ ) {
					if( P[i] > max ) {
						max = P[i];
						idx = i;
					}
				}
				putchar(idx+'A');
				P[idx]--, tot--;
			}
			
			putchar(' ');
			
			
			for( int i = 0; i < n; i++ ) {
				if( P[i]*2 > tot ) {
					assert(1 == 0);
				}
			}
		}
		
		puts("");
		
	}
	
	return 0;
}
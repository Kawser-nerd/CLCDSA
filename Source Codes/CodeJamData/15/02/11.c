#include <stdio.h>
#include <stdlib.h>

#define TAM			1002

int a[TAM], needed[TAM];

int main ( )
{
	int ntc, test, n, i, j, special;
	scanf ( "%d", &ntc );
	for ( test = 1; test <= ntc; ++test ) {
		scanf ( "%d", &n );
		for ( i = 0; i < n; ++i )
			scanf ( "%d", &a[i] );

		int ans = TAM, val;
		for ( i = 1; i < TAM; ++i ) {
			needed[i] = 0;
			for ( j = 0; j < n; ++j )
				needed[i] += ( a[j] + i - 1 ) / i - 1;
			val = needed[i] + i;
			if ( val < ans ) ans = val;
		}

		printf ( "Case #%d: %d\n", test, ans );
	}
	return 0;
}

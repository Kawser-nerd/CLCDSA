#include <stdio.h>
#include <stdlib.h>

#define TAM			1002

char s[TAM];

int main ( )
{
	int ntc, test, n;
	scanf ( "%d", &ntc );
	for ( test = 1; test <= ntc; ++test ) {
		scanf ( "%d%s", &n, s );
		int ans = 0, i, sum = 0;
		for ( i = 0; i <= n; ++i ) {
			if ( s[i] != '0' )
				if ( sum < i ) {
					ans += i-sum;
					sum = i;
				}
			sum += s[i]-'0';
		}
	
		printf ( "Case #%d: %d\n", test, ans );
	}
	return 0;
}

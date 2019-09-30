#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define maxN 100

int coin[maxN];
bool m[maxN];

int main( void ) {
    int T;
    scanf("%i", &T);

    int t;
    for( t = 1; t <= T; t++ ) {
	int C, D, V;
	scanf("%i %i %i", &C, &D, &V);

	int c;
	for( c = 0; c < D; c++ )
	    scanf("%i", &coin[c]);

	int ans = 0, lastNotFound = -1;
	while( true ) {
	    int i, j;

	    memset(m, 0, sizeof(m)); 

	    m[0] = 1;
	    for( i = 0; i < D; i++ )
		for( j = V; j >= coin[i]; j-- )
		    m[j] |= m[j - coin[i]];

	    bool ok = true;
	    for( i = 1; i <= V; i++ )
		if( m[i] == 0 ) {
		    lastNotFound = i;
		    ok = false;

		    break;
		}
	    
	    if( ok ) break;

	    coin[D++] = lastNotFound;
	    ans += 1;
	}
    
	printf("Case #%i: %i\n", t, ans);
    }

    return 0;
}

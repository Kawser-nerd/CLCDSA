#include <stdio.h>

int main( void ) {
    int T;
    scanf("%i", &T);

    int t;
    for( t = 1; t <= T; t++ ) {
	int R, C, W;
	scanf("%i %i %i", &R, &C, &W);
	
	int ans = (C / W) * (R - 1); 

	printf("Case #%i: %i\n", t, (W - 1) + (C / W) + (C % W ? 1 : 0) + ans);
    }

    return 0;
}

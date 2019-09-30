#include <stdio.h>

int T, t, n, i, x[1000], s0, s1, min;

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d", &n );
		for( i = s0 = s1 = 0, min = 1<<20; i < n; i++ )
		{
			scanf( "%d", &x[i] );
			s0 ^= x[i];
			s1 += x[i];
			if( x[i] < min ) min = x[i];
		}
		printf( "Case #%d: ", t );
		if( s0 )
		{
			printf( "NO\n" );
			continue;
		}
		else printf( "%d\n", s1 - min );
	}
	return 0;
}

#include <stdio.h>

int T, t, d1, d2, g1, g, ok;
long long n;

int gcd( int a, int b )
{
	while(b)
	{
		int t = a%b;
		a = b;
		b = t;
	}
	return a;
}

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%lld%d%d", &n, &d1, &g1 );
		printf( "Case #%d: ", t );
		if( ( d1 > 0 && g1 == 0 ) || ( d1 < 100 && g1 == 100 ) )
		{
			printf( "Broken\n" );
			continue;
		}
		if(d1)
		{
			g = gcd( d1, 100 );
			d1 /= g;
			d2 = 100 / g;
		}
		else d2 = 1;
		if( d2 <= n ) printf( "Possible\n" );
		else printf( "Broken\n" );
	}
	return 0;
}

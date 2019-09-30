#include <stdio.h>

#define MAX 1001

int T, t, n, m, i, tmp;

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d", &n );
		for( i = m = 0; i < n; i++ )
		{
			scanf( "%d", &tmp );
			if( i+1 != tmp ) m++;
		}
		printf( "Case #%d: %d\n", t, m );
	}
	return 0;
}

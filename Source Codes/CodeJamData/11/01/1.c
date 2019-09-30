#include <stdio.h>

char buf[1];
int T, t, n, i, j, r[100], p[2][100], q, x[2], y[2], pos[2];

void move( int bot )
{
	if( y[bot] < x[bot] )
	{
		if( pos[bot] < p[bot][y[bot]] ) pos[bot]++;
		if( pos[bot] > p[bot][y[bot]] ) pos[bot]--;
	}
}

int main()
{
	scanf( "%d", &T );
	for( t = 1; t <= T; t++ )
	{
		scanf( "%d", &n );
		for( i = x[0] = x[1] = 0; i < n; i++ )
		{
			scanf( "%s", buf );
			q = r[i] = buf[0] == 'B';
			scanf( "%d", &p[q][x[q]++] );
		}
		for( i = j = y[0] = y[1] = 0, pos[0] = pos[1] = 1; i < n; i++ )
		{
			q = r[i];
			while( pos[q] != p[q][y[q]] )
			{
				move(q);
				move(1-q);
				j++;
			}
			move(1-q);
			y[q]++;
			j++;
		}
		printf( "Case #%d: %d\n", t, j );
	}
	return 0;
}

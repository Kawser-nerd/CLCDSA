#include <cstdio>
#include <cstring>

int n;
bool us[1<<20];
double dp[1<<20];

int wt( int pos, int ma, int &r )
{
	if ( pos >= n )
		return wt( 0, ma, r );
	if ( !(ma&(1<<pos)) )
	{
		r = pos;
		return 0;
	}
	return 1 + wt( pos+1, ma, r );
}

double getDP( int ma )
{
	if ( us[ma] )
		return dp[ma];
	if ( ma == (1<<n)-1 )
		return 0.0;
	int i, j, k;
	double sol = 0;
	for ( i = 0; i < n; i++ )
	{
		k = wt( i, ma, j );
		//printf( "WAIT %d %d %d %d\n", n, ma, i, k );
		sol += 1.0/n*(getDP( ma|(1<<j) ) + (double) n-k );
	}
	us[ma] = 1;
	return dp[ma] = sol;
}

int main()
{
	int t, T;
	char s[256];
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		scanf( "%s", s );
		n = strlen( s );
		memset( us, 0, sizeof( us ) );
		int ma = 0;
		for ( int i = 0; i < n; i++ )
		{
			if ( s[i] == 'X' )
				ma |= (1<<i);
		}
		printf( "Case #%d: %.12lf\n", t, getDP( ma ) );
	}
	return 0;
}

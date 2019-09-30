#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n;
long long b;
long long x[64];
long long y[64];

int main()
{
	int i, j;
	long long l, ll, bet;
	int t, T;
	double ans = 0, cur;
	scanf( "%d", &T );
	for ( t = 1; t <= T; t++ )
	{
		memset( x, 0, sizeof( x ) );
		scanf( "%lld %d", &b, &n );
		for ( i = 0; i < n; i++ )
			scanf( "%lld", &x[i] );
		sort( x, x + 37 );
		x[37] = (1LL<<62);
		ans = 0;
		for ( i = 0; i <= 36; i++ )
		{
			if ( x[i] < x[i+1] )
			{
				cur = 0;
				bet = 0;
				for ( j = 0; j <= i; j++ )
				{
					bet += x[j];
				}
				ll = (b+bet)/(i+1);
				//printf( "BET %d %lld Beofer %lld\n", i, l, x[i+1] );
				if ( ll >= x[i+1] )
					ll = x[i+1]-1;
				for ( l = ll-10; l <= ll; l++ )
				{
					if ( l < x[i] )
						continue;
					bet = 0;
					for ( j = 0; j <= i; j++ )
					{
						bet += (l-x[j]);
					}
					long long rest = b - bet;
					//printf( "BET %d %lld Beofer %lld %lld %lld %lld\n", i, l, x[i+1], rest, bet, b );
					for ( int k = i; k >= -1; k-- )
					{
						memcpy( y, x, sizeof( x ) );
						long long ch = 0;
						for ( j = k+1; j <= i; j++ )
						{
							y[j] = l+1;
							ch++;
						}
						if ( ch > rest )
						{
							continue;
						}
						cur = 0;
						int cnt = 0;
						for ( j = 0; j <= i; j++ )
						{
							if ( y[j] <= l )
							{
								cur = cur + (double)(l-y[j])*36.0;
								cnt++;
							}
						}
						cur = cur/cnt - bet - ch;
						//printf( "%d %lld %lf (%lld)\n", i, l, cur, bet );
						if ( cur > ans )
							ans = cur;
					}
				}
			}
		}
		printf( "Case #%d: %.12lf\n", t, ans );
	}
	return 0;
}

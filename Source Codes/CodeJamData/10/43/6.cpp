#include<iostream>
#include<cstdio>

using namespace std;

int father[1010];
int maxx[1010];
int maxy[1010];
int minxy[1010];
int X1[1010], X2[1010], Y1[1010], Y2[1010];

int findfather(int t)
{
	if ( father[t] == -1 ) return t;
	else return (father[t] = findfather(father[t]));
}

bool intersect(int a, int b)
{
	if (Y2[a] + 1 < Y1[b]) return false;
	if (Y2[b] + 1 < Y1[a]) return false;
	if (X2[a] + 1 < X1[b]) return false;
	if (X2[b] + 1 < X1[a]) return false;
	if (Y2[a] < Y1[b] && X2[a] < X1[b] ) return false;
	if (Y2[b] < Y1[a] && X2[b] < X1[a] ) return false;
	return true;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int test_cases, casen = 0, R;
	for ( scanf( "%d", &test_cases ); test_cases > 0; test_cases -- )
	{
		scanf( "%d", &R );
		for (int i = 0; i < R; i++ )
			scanf( "%d %d %d %d", &X1[i], &Y1[i], &X2[i], &Y2[i] );
		memset( father, 0xff, sizeof( father ) );
		for (int i = 0; i < R; i++ )
			for (int j = i + 1; j < R; j++ )
				if ( intersect( i, j ) )
				{
					if ( findfather(i) != findfather(j) )
						father[findfather(i)] = findfather(j);
				}
		for (int i = 0; i < R; i++ )
		{
			minxy[i] = 1000000000;
			maxx[i] = 0; maxy[i] = 0;
		}
		for (int i = 0; i < R; i++ )
		{
			int t = findfather(i);
			minxy[t] <?= X1[i] + Y1[i];
			maxx[t] >?= X2[i]; maxy[t] >?= Y2[i];
		}
		int ans = 0;
		for (int i = 0; i < R; i++ )
		if ( father[i] == -1 )
			ans >?= maxx[i] + maxy[i] - minxy[i] + 1;
		
		printf( "Case #%d: %d\n", ++casen, ans );
	}
}

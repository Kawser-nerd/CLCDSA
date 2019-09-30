#include<iostream>
#include<cstdio>

using namespace std;

bool ok;
int fardist;
int A[120][120];
int K;

void diff(int a, int b, int c, int d)
{
	if ( a < 0 || a > 2 * K || b < 0 || b > 2 * K || c < 0 || c > 2 * K || d < 0 || d > 2 * K ) return;
	if ( A[a][b] == -1 || A[c][d] == -1 ) return;
	if ( A[a][b] != A[c][d] ) ok = false;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int test_cases, casen = 0;
	for ( scanf( "%d", &test_cases ); test_cases > 0; test_cases -- )
	{
		memset( A, 0xff, sizeof( A ) );
		scanf( "%d", &K );
		for (int i = 0; i < K; i++ )
			for (int j = K - i; j <= K + i; j += 2 )
				scanf( "%d", &A[i][j] );
		for (int i = K; i < 2 * K - 1; i++ )
			for (int j = K - (2 * K - 2 - i); j <= K + (2 * K - 2 - i); j += 2 )
				scanf( "%d", &A[i][j] );
		int mindist = 200;
		for (int i = 0; i <= 2 * K; i++ )
			for (int j = 0; j <= 2 * K; j++ )
				{
					ok = true; fardist = 0;
					for (int k = 0; k <= 2 * K; k++ )
						for (int l = 0; l <= 2 * K; l++ )
						if ( A[k][l] != -1 )
						{
							//if ( i == 2 && j == K + 1 )	cout << k << " " << l << " " << i * 2 - k << " " << j * 2 - l << " " << A[k][l] << " " << A[i * 2 - k][j * 2 - l] << endl;
							fardist >?= abs(k - i) + abs(l - j);
							diff( k, l, i * 2 - k, j * 2 - l );
							diff( k, l, i * 2 - k, l );
							diff( k, l, k, j * 2 - l );
						}

					if ( ok ) mindist <?= fardist;
				}
		printf( "Case #%d: %d\n", ++casen, (mindist + 1) * (mindist + 1) - K * K);
	}
}

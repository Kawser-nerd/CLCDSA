#include<iostream>
#include<cstdio>

using namespace std;

int M[1040];
int Price[12][1040], P;
int MinCost[12][1040][12];

void update( int &A, int b, int c, int d )
{
	if ( b == -1 || c == -1 ) return;
	if ( A == -1 ) A = b + c + d;
	else if ( A > b + c + d ) A = b + c + d;
}

int main()
{
	freopen( "in.txt", "r", stdin );
	freopen( "out.txt", "w", stdout );
	int test_cases, casen = 0;
	scanf( "%d", &test_cases ); 
	for ( ; test_cases > 0; test_cases -- )
	{
		scanf( "%d", &P );
		for (int i = 0; i < (1 << P); i++ )
		{
			scanf( "%d", &M[i] );
			M[i] = P - M[i];
		}
		for (int i = P - 1; i >= 0; i-- )
			for (int j = 0; j < (1 << i); j++ )
				scanf( "%d", &Price[i][j] );
		//cout << "here\n";
		memset( MinCost, 0xff, sizeof( MinCost ) );
		for (int j = 0; j < (1 << P); j++ )
			MinCost[P][j][M[j]] = 0;
		for (int i = P - 1; i >= 0; i-- )
			for (int j = 0; j < (1 << i); j++ )
			{
				for (int k = 0; k <= P; k++ )
					for (int l = 0; l <= P; l++ )
					{
						//if ( i == 0 && k == 0 && l == 1 ) cout << MinCost[i + 1][j * 2][k] << " " << MinCost[i + 1][j * 2 + 1][l] << endl;
						update( MinCost[i][j][max(k, l)], MinCost[i + 1][j * 2][k], MinCost[i + 1][j * 2 + 1][l], 0 );
						if ( k > 0 || l > 0 ) update( MinCost[i][j][max(k, l) - 1], MinCost[i + 1][j * 2][k], MinCost[i + 1][j * 2 + 1][l], Price[i][j] );
					}	
			}	
		printf( "Case #%d: %d\n", ++casen, MinCost[0][0][0] );
	}
}

#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

double OWP[110];
double OOWP[110];
char match[110][110];

main(){
	int t, tt = 0;
	int n, i, j;
	int cnt[110];
	int win[110];
	
	freopen( "AL.in", "r", stdin );
	freopen( "AL.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d", &n );
		for ( i = 0; i < n; i ++ )
			scanf ( "%s", match[i] );
		memset ( cnt, 0, sizeof ( cnt ) );
		memset ( win, 0, sizeof ( win ) );
		for ( i = 0; i < n; i ++ )
			for ( j = 0; j < n; j ++ )
				if ( match[i][j] != '.' ){
					cnt[i] ++;
					if ( match[i][j] == '1' )
						win[i] ++;
				}
		memset ( OWP, 0, sizeof ( OWP ) );
		memset (OOWP, 0, sizeof (OOWP ) );
		for ( i = 0; i < n; i ++ ){
			for ( j = 0; j < n; j ++ )
				if ( match[i][j] != '.' )
					OWP[i] += ( win[j] - ( match[i][j] == '0' ) ) * 1.0 / ( cnt[j] - 1 );
			OWP[i] /= cnt[i];
		}
		for ( i = 0; i < n; i ++ ){
			for ( j = 0; j < n; j ++ )
				if ( match[i][j] != '.' )
					OOWP[i] += OWP[j];
			OOWP[i] /= cnt[i];
		}
		printf( "Case #%d:\n", ++ tt );
		for ( i = 0; i < n; i ++ )
			printf( "%.15lf\n", 0.25 * win[i] * 1.0 / cnt[i] + 0.5 * OWP[i] + 0.25 * OOWP[i] );
	}
	
	return 0;
}

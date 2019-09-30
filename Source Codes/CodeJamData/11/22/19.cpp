#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

pair< int, int > a[210];
int sum[210];

main(){
	int t, tt = 0;
	int n, P, V;
	int i, j;
	double dis;
	double maximum;
	
//	freopen( "BL.in", "r", stdin );
//	freopen( "BL.out", "w", stdout );
	
	scanf ( "%d", &t );
	while( t -- ){
		scanf ( "%d %lf", &n, &dis );
		for ( i = 0; i < n; i ++ ){
			scanf ( "%d %d", &P, &V );
			a[i] = make_pair( P, V );
		}
		maximum = 0;
		sort ( a, a + n );
		for ( i = 0; i < n; i ++ )
			maximum = max( maximum, 0.5 * ( a[i].second - 1 ) * dis );
		sum[0] = 0;
		for ( i = 0; i < n; i ++ )
			sum[ i + 1 ] = sum[i] + a[i].second;
		for ( i = 0; i < n; i ++ )
			for ( j = i + 1; j < n; j ++ )
				maximum = max( maximum, 0.5 * ( ( sum[ j + 1 ] - sum[i] - 1 ) * dis - ( a[j].first - a[i].first ) ) );
		printf( "Case #%d: %.15lf\n", ++ tt, maximum );
	}
	
	return 0;
}

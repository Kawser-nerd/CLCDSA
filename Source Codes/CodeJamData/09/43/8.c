#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int m[20][30];
int cross[20][20];
int dp[1<<17];
int good[1<<17];
int N;

int go( int mask ) {
  int i, min, n, submask;
  if ( mask == ( 1 << N ) - 1 )
    return 0;
  if ( dp[mask] > 0 )
    return dp[mask];

  min = 1000000;

  submask = ( ( 1 << N ) - 1 ) & ( ~mask );
  for ( i = submask; i > 0; i = ( i - 1 ) & submask ) 
    if ( ( i & mask ) == 0 && good[i] ) {
      n = go( mask | i ) + 1;
      if ( min > n ) min = n;
    }
  return dp[mask] = min;
}

int main(){
  int T, K, i, j, k, ca;

  scanf("%d\n", &T);
  for ( ca = 1; ca <= T; ca++ ) {
    scanf("%d %d\n", &N, &K );

    for ( i = 0; i < N; i++ )
      for ( j = 0; j < K; j++ )
	scanf("%d\n", &m[i][j]);

    memset( cross, 0, sizeof( cross ) );
    for ( i = 0; i < N; i++ )
      for ( j = 0; j < N; j++ )
	for ( k = 0; k < K; k++ )
	  if ( m[i][k] == m[j][k] )
	    cross[i][j] = cross[j][i] = 1;
	  else if ( k > 0 &&
		    ( ( m[i][k-1] > m[j][k-1] && m[i][k] < m[j][k] )
		      || 
		      ( m[i][k-1] < m[j][k-1] && m[i][k] > m[j][k] ) ) )
	    cross[i][j] = cross[j][i] = 1;

    for ( i = 0; i < ( 1 << N ); i++ ) {
      good[i] = 1;
      for ( j = 0; j < N; j++ )
	if ( ( i & ( 1 << j ) ) > 0 )
	  for ( k = j + 1; k < N; k++ )
	    if ( ( i & ( 1 << k ) ) > 0 )
	      if ( cross[j][k] )
		good[i] = 0;
    }

    memset( dp, 0, sizeof( dp ) );
    printf("Case #%d: %d\n", ca, go( 0 ) );
  }

  return 0;
}

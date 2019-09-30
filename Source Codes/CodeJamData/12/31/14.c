/* @JUDGE_ID: 18678EK -1 C */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int a[1005][15];
int M[1005];
int u[1005];
int f = 0;

int dfs( int now ) {
  int i;
  if ( u[ now ] ) {
    f = 1;
    return;
  }

  u[now] = 1;
  for ( i = 0; i < M[now] && !f; i++ ) {
    dfs( a[now][i] );
  }
}

int main(){
  int T, ca;
  int i, j, k, N;

  scanf("%d\n", &T );

  for ( ca = 1; ca <= T; ca++ ) {
    scanf("%d\n", &N );

    for ( i = 0; i < N; i++ ) {
      scanf("%d\n", &M[i] );

      for ( j = 0; j < M[i]; j++ ) {
	scanf("%d\n", &a[i][j] );
	a[i][j]--;
      }
    }

    f = 0;
    for ( i = 0; i < N && !f; i++ ) {
      memset( u, 0, sizeof( u ) );
      dfs( i );
    }

    if ( f )
      printf("Case #%d: Yes\n", ca);
    else
      printf("Case #%d: No\n", ca );
  }

  return 0;
}

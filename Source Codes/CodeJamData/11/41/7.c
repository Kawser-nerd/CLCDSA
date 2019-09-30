#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int B[1005];
int E[1005];
int w[1005];
int u[1005];

int main(){
  int T, ca;
  int X, S, R, t, N;
  int i, j;
  double time;
  int d;
  double dist;
  double tleft, tu;
  int m;

  scanf("%d\n", &T);

  for ( ca = 1; ca <= T; ca++ ) {
    scanf("%d %d %d %d %d\n", &X, &S, &R, &t, &N );

    for ( i = 0; i < N; i++ ) {
      scanf("%d %d %d\n", &B[i], &E[i], &w[i] );
    }

    time = 0.0;
    d = 0;
    tleft = (double)t;

    for ( i = 0; i < N; i++ ) {
      dist = B[i] - d;
      
      tu = dist / (double) R;
      if ( tu > tleft ) tu = tleft;
      tleft -= tu;
      dist -= (double) ( tu * R );
      time += tu;
      tu = dist / (double) S;
      time += tu;
      d = B[i];

      /* Ride on i */
      dist = E[i] - d;

      tu = dist / (double) ( S + w[i] );
      time += tu;
      d = E[i];
    }

    dist = X - d;
      
    tu = dist / (double) R;
    if ( tu > tleft ) tu = tleft;
    tleft -= tu;
    dist -= (double) ( tu * R );
    time += tu;
    tu = dist / (double) S;
    time += tu;
    d = X;

    memset( u, 0, sizeof( u ) );
    for ( i = 0; i < N; i++ ) {
      m = -1;

      for ( j = 0; j < N; j++ ) {
	if ( !u[j] && ( m == -1 || w[j] < w[m] ) ) {
	  m = j;
	}
      }

      if ( m == -1 ) break;
      u[m] = 1;

      dist = E[m] - B[m];
      tu = dist / (double) ( R + w[m] );
      if ( tu > tleft ) tu = tleft;
      tleft -= tu;
      time += tu;

      dist = tu * ( R + w[m] );
      tu = dist / (double) ( S + w[m] );
      time -= tu;
    }

    printf("Case #%d: %.10lf\n", ca, time );
  }

  return 0;
}

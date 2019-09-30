#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char a[45][45];
int count[45];

int main(){
  int T, ca, N, i, j, swap, t;

  scanf("%d\n", &T );

  for ( ca = 1; ca <= T; ca++ ) {
    memset( a, 0, sizeof( a ) );
    scanf("%d\n", &N ); 

    for ( i = 0; i < N; i++ ) {
      scanf("%s\n", a[i] );
    }

    swap = 0;

    memset( count, 0, sizeof( count ) );
    for ( i = 0; i < N; i++ ) {
      for ( j = 0; j < N; j++ )
	if ( a[i][j] == '1' )
	  count[i] = j;
    }

    for ( i = 0; i < N; i++ ) {
      if ( count[i] >= i + 1 ) {
	/* Find one to move up */
	for ( j = i + 1; j < N; j++ )
	  if ( count[j] < i + 1 )
	    break;

	for ( ; j > i; j-- ) {
	  t = count[j];
	  count[j] = count[j-1];
	  count[j-1] = t;
	  swap++;
	}

      }
    }
    printf("Case #%d: %d\n", ca, swap );
  }

  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAXP 1000025
int prime[MAXP+5];
long long pl[MAXP+5];
int pt;

int main(){
  int T, ca;
  long long i, j, count;
  long long N, now;
  int pt = 0;

  for ( i = 2; i <= MAXP; i++ ) {
    prime[i] = 1;
  }

  for ( i = 2; i <= MAXP; i++ ) {
    if ( prime[i] )
      for ( j = i * i; j <= MAXP; j += i )
	prime[j] = 0;
  }

  for ( i = 2; i <= MAXP; i++ ) {
    if ( prime[i] )
      pl[pt++] = i;
  }

  scanf("%d\n", &T );

  for ( ca = 1; ca <= T; ca++ ) {
    scanf("%lld\n", &N );

    count = 1;
    for ( i = 0; i < pt; i++ ) {
      now = pl[i] * pl[i];

      while ( now <= N ) {
	count++;
	now *= pl[i];
      }
    }
    if ( N == 1 ) count = 0;
    if ( N == 2 ) count = 1;

    printf("Case #%d: %lld\n", ca, count);
  }

  return 0;
}

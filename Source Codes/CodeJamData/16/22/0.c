#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>

int n;

int matches ( int a, char* s) {
  int i;
  for ( i = n-1; i >= 0; --i ) {
    if ( s[i] != '?' && a%10 != s[i]-'0' )
      return 0;
    a /= 10;
  }
  return 1;
}

void copy ( int a, char* s ) {
  int i;
  for ( i = n-1; i >= 0; --i ) {
    s[i] = '0' + a%10;
    a /= 10;
  }
}

char a[4], b[4];
int main() {
  int ntc, test;
  scanf ( "%d", &ntc );
  for ( test = 1; test <= ntc; ++test ) {
    scanf ( "%s%s", a, b );
    n = strlen(a);
    assert ( strlen(b) == n );
    int bestA = 1000, bestB = 0;
    int i, j;
    int p10 = 1;
    for ( i = 0; i < n; ++i ) p10 *= 10;
    for ( i = 0; i < p10; ++i )
      for ( j = 0; j < p10; ++j ) {
        if ( matches(i,a) && matches(j,b) )
          if ( abs(i-j) < abs(bestA-bestB) ) {
            bestA = i;
            bestB = j;
          }
      }
    copy(bestA,a);
    copy(bestB,b);
    printf ( "Case #%d: %s %s\n", test, a, b );
  }

  return 0;
}

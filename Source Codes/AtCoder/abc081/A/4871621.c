#include <stdio.h>

int main( void ) {
  char s[3];
  int i, cnt;
  scanf( "%s", s );

  cnt = 0;
  for ( i = 0; i < 3; i++ ) {
    if ( s[i] == '1' ) {
      cnt++;
    }
  }

  printf( "%d\n", cnt );

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf( "%s", s );
   ^
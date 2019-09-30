#include <stdio.h>

int main( void ) {
  int a, b;

  scanf( "%d %d", &a, &b );
  if ( (a * b) & 1 ) {
    printf( "Odd\n" );
  } else {
    printf( "Even\n" );
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf( "%d %d", &a, &b );
   ^
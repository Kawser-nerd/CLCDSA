#include <stdio.h>

int main( void ) {
  int i, n, cnt;
  int a[200];

  scanf( "%d", &n );

  i = 0;
  while ( i <= n ) {
    scanf( "%d", &a[i] );
      i++;
  }

  cnt = 0;
  i = 0;
  while ( (a[i] % 2) == 0 ) {
    a[i] = a[i] / 2;

    if ( i == (n - 1) ) {
      i = 0;
      cnt++;
      continue;
    }
    i++;
  }
  
  printf( "%d\n", cnt );
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf( "%d", &n );
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf( "%d", &a[i] );
     ^
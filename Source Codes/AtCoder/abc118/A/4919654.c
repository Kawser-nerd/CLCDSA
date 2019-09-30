#include <stdio.h>

int main(void) {

  int A, B ;
  int ans ;

  scanf("%d %d", &A, &B) ;

  if (B % A == 0) {
    ans = A + B ;
  }
  else {
    ans = B - A ;
  }

  printf("%d\n", ans) ;

  return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &A, &B) ;
   ^
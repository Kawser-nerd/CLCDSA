#include <stdio.h>

int
main(){
  int a, b;
  scanf("%d %d", &a, &b);
  if(a < 1 || 10000 < b)
    return 1;

  if( (a % 2) && (b % 2)  ){
    printf("Odd\n");
  } else {
    printf("Even\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int A, B, c, ans = 0;

  scanf("%d%d", &A, &B);

  c = abs(A - B);

  if(c % 10 <= 7){
    ans += c / 10;
    c = c % 10;
    if(c <= 3){
      ans += c;
    }else{
      ans += 1 + (abs(5 - c));
    }
  }else{
    ans += (c / 10) + 1;
    ans += 10 - (c % 10);
  }

  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &A, &B);
   ^
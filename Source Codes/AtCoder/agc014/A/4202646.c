#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  long long A, B, C, a, b, c, d, e, f, ans = 0, t = 0;

  scanf("%lld%lld%lld", &A, &B, &C);

  a = A, b = B, c = C;

  while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
    d = (B + C) / 2;
    e = (C + A) / 2;
    f = (A + B) / 2;
    A = d, B = e, C = f;
    ans++;
    if(A == a && B == b && C == c){
      t = 1;
      break;
    }
  }

  if(t == 1){
    printf("-1\n");
  }else{
    printf("%lld\n", ans);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld%lld", &A, &B, &C);
   ^
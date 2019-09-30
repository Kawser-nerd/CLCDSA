#include<stdio.h>
 
int main(){
  long long a, b, x, i, count = 0;
  
  scanf("%lld %lld %lld", &a, &b, &x);
  
  a = (a%x == 0) ? (a/x):(a/x + 1);
  b = b/x;
  for(i = a; i <= b; i++){
    count++;
  }
  
  printf("%lld\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %lld %lld", &a, &b, &x);
   ^
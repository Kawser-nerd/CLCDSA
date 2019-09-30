#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int gcd(int a, int b) {
  int v0 = a, v1 = b, v2 = a % b;
  while (v2 != 0) {
    v0 = v1;
    v1 = v2;
    v2 = v0 % v1;
  };
  return v1;
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}
 
int main(void){
  
  int a, b, n;
  int l;

  scanf("%d%d%d", &a, &b, &n);

  l = lcm(a, b);

  if(n % l == 0){
    printf("%d\n", n);
  }else{
    printf("%d\n", ((n / l) + 1) * l);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &n);
   ^
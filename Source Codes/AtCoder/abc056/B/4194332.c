#include<stdio.h>
#include<math.h>

int main(){
  int W, a, b, d;
  scanf("%d %d %d", &W, &a, &b);
  
  d = (fabs(b - (a + W)) <= (fabs)(a - (b + W))) ? (b - (a + W)):(a - (b + W));
  
  if(d > 0){
    printf("%d\n", d);
  } else {
    printf("0\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &W, &a, &b);
   ^
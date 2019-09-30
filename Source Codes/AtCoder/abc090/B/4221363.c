#include<stdio.h>

int main(){
  int A, B, a, b, c, d, e, p, count = 0;
  
  scanf("%d %d", &A, &B);
  
  for (int i = A; i <= B; i++){
    p = i;
    a = p%10;
    p /= 10;
    b = p%10;
    p /= 10;
    c = p%10;
    p /= 10;
    d = p%10;
    p /= 10;
    e = p%10;
    if(a == e && b == d){
      count++;
    }
  }
  
  printf("%d\n", count);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &A, &B);
   ^
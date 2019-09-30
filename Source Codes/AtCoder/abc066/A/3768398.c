#include <stdio.h>

int main(){
  int a, b, c;
  int min;
  scanf("%d %d %d", &a, &b, &c);
  min = b+c;
  if(c+a < min){
    min = c+a;
  }
  if(a+b < min){
    min = a+b;
  }
  printf("%d\n", min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^
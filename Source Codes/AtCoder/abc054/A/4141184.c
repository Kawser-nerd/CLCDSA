#include <stdio.h>

int main(void){
  int a, b;
  scanf("%d %d", &a, &b);
  if(a == 1) a = 14;
  if(b == 1) b = 14;
  if(a > b) printf("Alice\n");
  if(a < b) printf("Bob\n");
  if(a == b) printf("Draw\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^
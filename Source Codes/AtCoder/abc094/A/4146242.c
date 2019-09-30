#include <stdio.h>

int main(void){
  int a, b, x;
  scanf("%d %d %d", &a, &b, &x);
  int sub1 = x - a;
  int sub2 = b - sub1;
  if(sub1 >= 0 && sub2 >= 0) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &x);
   ^
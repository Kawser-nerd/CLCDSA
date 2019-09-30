#include <stdio.h>

int main(void){
  int n, a;
  scanf("%d" , &n);
  scanf("%d" , &a);
  while(n >= 0) n -= 500;
  n += 500;
  if(n <= a) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d" , &n);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d" , &a);
   ^
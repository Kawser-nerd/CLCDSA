#include <stdio.h>

int main(void){
  int a, b, c, d;
  scanf("%d %d %d", &a, &b, &c);
  int flag = 0;
  for(int i = 0; i < b; i++){
    d = a % b;
    d *= i;
    if(d % b == c) flag = 1;
  }
  if(flag) printf("YES\n");
  else printf("NO\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &a, &b, &c);
   ^
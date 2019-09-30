#include <stdio.h>

int main(void){
  int x, a, b, c;
  scanf("%d %d %d", &x, &a, &b);
  c = a - b;
  if(c >= 0){
    printf("delicious\n");
  }else{
    c = -c;
    if(x >= c) printf("safe\n");
    else printf("dangerous\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &x, &a, &b);
   ^
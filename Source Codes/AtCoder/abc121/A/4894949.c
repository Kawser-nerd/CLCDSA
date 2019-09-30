#include<stdio.h>
int main(void){
  int H, W, h, w, Hh, Ww, a;
  
  scanf("%d %d", &H, &W);
  scanf("%d %d", &h, &w);
  Hh = H - h;
  Ww = W - w;
  a = Hh * Ww;
  printf("%d\n", a);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &h, &w);
   ^
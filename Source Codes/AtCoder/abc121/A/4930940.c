#include <stdio.h>

int main(){
  int H, W, h_, w_;
  scanf("%d %d", &H, &W);
  scanf("%d %d", &h_, &w_);
  printf("%d", H * W - H * w_ - W * h_ + h_ * w_);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &H, &W);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &h_, &w_);
   ^
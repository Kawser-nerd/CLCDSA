#include <stdio.h>
int max(int a, int b){
  if(a<b){
    return b;
  }else{
    return a;
  }
}
int main(){
  int a, b, c, x, y;
  scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
  int ans;
  ans = a * x + b * y;
  int tmp;
  tmp = c * (2 * y) + a * max(0, x-y);
  if (tmp < ans){
    ans = tmp;
  }
  tmp = c * (2 * x) + b * max(0, y-x);
  if (tmp < ans){
    ans = tmp;
  }
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d", &a, &b, &c, &x, &y);
   ^
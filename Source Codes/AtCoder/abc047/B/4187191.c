#include<stdio.h>

int main(){
  int W, H, N, x, y, a, i, l, r, u, d;
  
  scanf("%d %d %d", &W, &H, &N);
  l = d = 0;
  u = H;
  r = W;
  for (i = 0; i < N; i++){
    scanf("%d %d %d", &x, &y, &a);
    if(a == 1 && l < x){
      l = x;
    } else if(a == 2 && r > x){
      r = x;
    } else if(a == 3 && d < y){
      d = y;
    } else if(a == 4 && u > y){
      u = y;
    }
  }
  
  if(u > d && r > l){
    printf("%d\n", (u - d)*(r - l));
  } else {
    printf("0\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &W, &H, &N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &x, &y, &a);
     ^
#include<stdio.h>

int main(){
  int A, B, C, D, ans;
  
  scanf("%d %d %d %d", &A, &B, &C, &D);
  if(A >= C && B >= D){
    ans = D - A;;
  } else if(A >= C && B < D){
    ans = B - A;
  }	 else if(A < C && B >= D){
    ans = D - C;
  } else if(A < C && B < D){
    ans = B - C;
  }
  
  if(ans < 0){
    ans = 0;
  }
  
  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d", &A, &B, &C, &D);
   ^
#include<stdio.h>

int main(){
  int N, l, r, f;
  
  scanf("%d", &N);
  
  for (int i = 0; i < N; i++){
    scanf("%d %d", &l, &r);
    f += r - l + 1;
  }
  
  printf("%d\n", f);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &l, &r);
     ^
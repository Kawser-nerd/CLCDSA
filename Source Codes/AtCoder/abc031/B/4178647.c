#include<stdio.h>

int main(){
  int L, H, N, a[50] = {0}, b, i;
  scanf("%d %d", &L, &H);
  scanf("%d", &N);
  for (i = 0; i < N; i++){
    scanf("%d", &b);
    if(b < L){
      a[i] = L - b;
    } else if(b > H){
      a[i] = -1;
    }
  }
  
  for (i = 0; i < N; i++){
    printf("%d\n", a[i]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &L, &H);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &b);
     ^
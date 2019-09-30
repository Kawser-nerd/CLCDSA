#include <stdio.h>
int main(){
  int i, N, sum=0, l, r;
  scanf("%d", &N);
  for (i=0; i<N; i++){
    scanf("%d%d", &l,&r);
    sum = sum + r - l + 1;
  }
  printf("%d", sum);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &l,&r);
     ^
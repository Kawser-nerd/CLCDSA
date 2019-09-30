#include <stdio.h>
int main(){
  int N, K, x, sum=0;
  scanf("%d%d", &N, &K);
  for (int i=0; i<N ;i++){
    scanf("%d",&x);
    if (K-x > x){
      sum += 2 * x;
    }
    else{
      sum += 2 * (K - x);
    }
  }
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &N, &K);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x);
     ^
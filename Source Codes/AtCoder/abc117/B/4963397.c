#include <stdio.h>

int main(void){
  int N, L, sum=0, max;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",&L);
    sum+=L;
    if(L>max) max=L;
  }
  if(sum - max > max) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&L);
     ^
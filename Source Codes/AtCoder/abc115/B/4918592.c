#include <stdio.h>

int main(void){
  int N, p, sum=0, max=0;
  int i;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&p);
    sum+=p;
    if(p>max) max=p;
  }
  printf("%d\n",sum-max/2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&p);
     ^
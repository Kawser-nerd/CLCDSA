#include <stdio.h>

int main(void){
  int N,a;
  int max,min;

  scanf("%d",&N);
  scanf("%d",&a);
  max = min = a;
  for(int i = 1;i < N;i++){
    scanf("%d",&a);
    if(max < a) max = a;
    if(min > a) min = a;
  }

  printf("%d\n",max-min);


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
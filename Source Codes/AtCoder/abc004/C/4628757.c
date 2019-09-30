#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  N %= 30;

  int data[6] = {1,2,3,4,5,6};
  for(int i = 0;i < N;i++){
    int tmp = data[i%5];
    data[i%5] = data[i%5+1];
    data[i%5+1] = tmp;
  }

  for(int i = 0;i < 6;i++){
    printf("%d",data[i]);
  }
  printf("\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
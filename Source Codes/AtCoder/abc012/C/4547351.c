#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int gap = 2025-N;

  for(int i = 1;i < 10;i++){
    for(int j = 1;j < 10;j++){
      if(i * j == gap) printf("%d x %d\n",i,j);
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
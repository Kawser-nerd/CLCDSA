#include <stdio.h>

int main(void){
  int N;
  int max = 0;
  int ans = 1;
  scanf("%d",&N);

  for(int i = 1;i <= N;i++){
    int j = i;
    int counter = 0;
    while(j%2 == 0){
      j /= 2;
      counter++;
    }

    if(max < counter){
      max = counter;
      ans = i;
    }
  }

  printf("%d",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
#include <stdio.h>

int main(void){
  int N;
  scanf("%d",&N);

  int cnt = 0;
  int sum = 0;
  int a;
  for(int i = 0;i < N;i++){
    scanf("%d",&a);
    if(a) cnt++;
    sum += a;
  }

  printf("%d\n",(sum+cnt-1)/cnt);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
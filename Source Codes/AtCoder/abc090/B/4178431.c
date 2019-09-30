#include <stdio.h>

int main(void){
  long A,B;
  int ans = 0;
  scanf("%ld%ld",&A,&B);

  for(int i = A;i <= B;i++){
    if(i%10 == i/10000){
      if((i/1000)%10 == (i/10)%10){
        ans++;
      }
    }
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld%ld",&A,&B);
   ^
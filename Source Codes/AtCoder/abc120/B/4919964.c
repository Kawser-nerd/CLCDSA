#include <stdio.h>

int main(){
  int A, B, K;
  int count = 1;
  int x = 100;
  int ans;
  int flag = 0;
  scanf("%d %d %d",&A,&B,&K);

  while(1){
    if(A % x == 0 && B % x == 0){
      ans = x;
      if(count == K){
        flag = 1;
        break;
      }else{
        count ++;
      }
    }
    if(flag == 1){
      break;
    }
    x --;
  }

  printf("%d",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&K);
   ^
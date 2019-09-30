#include <stdio.h>
#include <math.h>

int main(void){
  int X,num;
  scanf("%d",&X);

  if(X == 1 || X == 2){
    printf("1\n");
    return 0;
  }
  int flag[X];
  for(int i = 0;i < X;i++){
    flag[i] = 0;
  }

  for(int a = 1;a <= X;a++){
    for(int b = 2;b < X;b++){
      num = pow(a,b);
      if(num <= X){
        flag[num-1] = 1;
      }else{
        break;
      }
    }
  }

  for(int i = X-1;i >= 0;i--){
    if(flag[i]){
      printf("%d\n",i+1);
      return 0;
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&X);
   ^
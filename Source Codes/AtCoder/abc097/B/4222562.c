#include<stdio.h>
#include<math.h>

int main(){
  int X, Y, max = 0, p;
  
  scanf("%d", &X);
  Y = sqrt(X);
  for (int i = 1; i <= Y; i++){
    p = i;
    for(int j = 1; j < 10; j++){
      p *= i;
      if(p <= X && max < p){
        max = p;
      }
    }
  }
  
  printf("%d\n", max);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &X);
   ^
#include <stdio.h>

int main() {
  int a,b,i;
  scanf("%d%d",&a,&b);
  
  int result = 0;
  for(i = a; i <= b; i++){
    if(i/10000 == i%10 && i%10000/1000 == i%100/10){
      result++;
    }
  }
  printf("%d\n", result);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^
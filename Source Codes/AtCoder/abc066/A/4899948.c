#include <stdio.h>
#include <string.h>
int main(){
  int a, b, c;

  scanf("%d%d%d", &a, &b, &c);

  if(a >= b){
    if(a >= c){
      printf("%d", b + c);
    }else{
      printf("%d", b + a);
    }
  }else if(b >= a){
    if(b >= c){
      printf("%d", a + c);
    }else{
      printf("%d", a + b);
    }
  }else if(c >= a){
    if(c >= b){
      printf("%d", b + a);
    }else{
      printf("%d", a + c);
    }
  }
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &c);
   ^
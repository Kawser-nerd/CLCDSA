#include<stdio.h>
int a, b;
int main(){
  scanf("%d%d", &a, &b);
  if(a==0 || b==0){
    puts("Zero");
  }else if(a<0 && b>0){
    puts("Zero");
  }else if(a>0){
    puts("Positive");
  }else if((a&1)^(b&1)){
    puts("Positive");
  }else{
    puts("Negative");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &a, &b);
   ^
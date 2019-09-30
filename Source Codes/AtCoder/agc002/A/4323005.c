#include<stdio.h>
int main(){
  int a,b;
  scanf("%d%d",&a,&b);
  if(a<0){
    if(b>=0){
      puts("Zero");
    }
    else {
      if((b-a)%2){
        puts("Positive");
      }
      else {
        puts("Negative");
      }
    }
  }
  else{
    puts("Positive");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^
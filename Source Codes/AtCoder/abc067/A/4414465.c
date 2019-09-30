#include <stdio.h>

int main(){
  int a,b;
scanf("%d",&a);
scanf("%d",&b);
  if(a%3==0||b%3==0||(a+b)%3==0){
   printf("Possible"); 
  }else{
   printf("Impossible"); 
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&a);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&b);
 ^
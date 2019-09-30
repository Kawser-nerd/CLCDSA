#include<stdio.h>
short Y;
int main(){
  scanf("%hd", &Y);
  if(Y%400==0){
    printf("YES\n");
  }else if(Y%100==0){
    printf("NO\n");
  }else if(Y%4==0){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd", &Y);
   ^
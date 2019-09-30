#include <stdio.h>
int main(void){
  char ox;
  int price=700;
  scanf("%c",&ox);
  if(ox=='o')price+=100;
  scanf("%c",&ox);
  if(ox=='o')price+=100;
  scanf("%c",&ox);
  if(ox=='o')price+=100;
  printf("%d",price);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&ox);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&ox);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&ox);
   ^
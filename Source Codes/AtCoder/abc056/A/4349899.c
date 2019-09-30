#include<stdio.h>
int main(void){
  char s,t;
  scanf("%c %c",&s,&t);
  if(s=='H'){
    if(t=='H') printf("H\n");
    else printf("D\n");
  }else{
    if(t=='H') printf("D\n");
    else printf("H\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c %c",&s,&t);
   ^
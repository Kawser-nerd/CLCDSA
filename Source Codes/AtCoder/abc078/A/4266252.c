#include<stdio.h>
#include<string.h>

int main(void){
  char x[2],y[2];
  scanf("%s %s",x,y);
  if(strcmp(x,y)==0){
    printf("=\n");
  }else if(strcmp(x,y)<0){
    printf("<\n");
  }else{
    printf(">\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",x,y);
   ^
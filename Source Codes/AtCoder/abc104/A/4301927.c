#include <stdio.h>
int main(void){
int R;
  scanf("%d",&R);
  if(R<1200){
    printf("ABC");
  }
  else if(R>=1200&&R<2800){
  printf("ARC");
  }
  else if(R>=2800){
  printf("AGC");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&R);
   ^
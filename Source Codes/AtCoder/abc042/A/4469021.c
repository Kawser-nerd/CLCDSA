#include<stdio.h>
int main(void){
  int cou,A,B,C;
  scanf("%d %d %d",&A,&B,&C);
  if(A==5){
    cou++;
  }else if(A==7){
    cou--;
  }else{
    cou+=55;
  }
  if(B==5){
    cou++;
  }else if(B==7){
    cou--;
  }else{
    cou+=55;
  }
  if(C==5){
    cou++;
  }else if(C==7){
    cou--;
  }else{
    cou+=55;
  }
  
  if(cou==1){
    printf("YES");
  }else{
    printf("NO");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&A,&B,&C);
   ^
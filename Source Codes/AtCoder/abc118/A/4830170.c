#include<stdio.h>
int main(void){
  int A=0,B=0;
  
 if( scanf("%d %d",&A,&B)==1);
  if(A==0){return 0;}
  if(B%A==0){printf("%d\n",A+B);}
  else{printf("%d\n",B-A);}
  
  return 0;
}
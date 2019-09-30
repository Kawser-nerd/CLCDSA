#include <stdio.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int A,B,C,D;
  scanf("%d%d%d%d",&A,&B,&C,&D);

  printf("%d\n",max(0,min(B,D)-max(A,C)));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&A,&B,&C,&D);
   ^
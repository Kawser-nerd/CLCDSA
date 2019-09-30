#include<stdio.h>
int X, A, B;
int main(){
  scanf("%d%d%d", &X, &A, &B);
  if(B<=A){
    printf("delicious\n");
  }else if(B<=A+X){
    printf("safe\n");
  }else{
    printf("dangerous\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &X, &A, &B);
   ^
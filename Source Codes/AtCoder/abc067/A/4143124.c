#include<stdio.h>
int main(void){
  int A,B,ok=0;
  scanf("%d %d",&A,&B);

  if(A%3==0){
    ok=1;
  }else if(B%3==0){
    ok=1;
  }else if((A+B)%3==0){
    ok=1;
  }


if(ok==1){
  printf("Possible");
}else{
  printf("Impossible");
}
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&A,&B);
   ^
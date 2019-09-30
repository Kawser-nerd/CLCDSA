#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,X;
    char S[10];
    scanf("%d %d %d %d",&A,&B,&C,&X);
   if(A+B>C+X){
       printf("Left");
   }else if(A+B==C+X){
       printf("Balanced");
   }else{
       printf("Right");
   }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&A,&B,&C,&X);
     ^
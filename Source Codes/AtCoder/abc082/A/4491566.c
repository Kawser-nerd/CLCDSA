#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,X;
    char S[10];
    scanf("%d %d",&A,&B);
    if((A+B)%2!=0){
   printf("%d",(A+B)/2+1);
    }else{
        printf("%d",(A+B)/2);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&A,&B);
     ^
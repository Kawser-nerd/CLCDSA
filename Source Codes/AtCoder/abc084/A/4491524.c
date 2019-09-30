#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,X;
    char S[10];
    scanf("%d",&A);
   
    printf("%d",48-A);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
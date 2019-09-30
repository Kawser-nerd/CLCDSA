#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,X;
    scanf("%d %d %d",&A,&B,&X);
    printf("%d",(A-B)%X);
    
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&X);
     ^
#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,X,cou=0,v[3];
    char S[10];
    scanf("%d %d %d",&A,&B,&C);
    if(A*B>=C){
        printf("%d",C);
    }else{
        printf("%d",A*B);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^
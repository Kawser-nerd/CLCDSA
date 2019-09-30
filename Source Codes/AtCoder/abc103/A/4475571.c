#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C;
    scanf("%d %d %d",&A,&B,&C);
    if((A>=B)&&(A>=C)){
        if(B>C){
            printf("%d",A-C);
        }else{
            printf("%d",A-B);
        }
    }else if((B>=A)&&(B>=C)){
        if(A>C){
            printf("%d",B-C);
        }else{
            printf("%d",B-A);
        }
    }else if((C>=B)&&(C>=A)){
        if(B>A){
            printf("%d",C-A);
        }else{
            printf("%d",C-B);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^
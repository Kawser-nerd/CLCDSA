#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,D;
    char S[3];
    scanf("%d %d %d %d",&A,&B,&C,&D);
    if(A>B){
        if(C>D){
            printf("%d",B+D);
        }else{
            printf("%d",B+C);
        }
    }else{
        if(C>D){
            printf("%d",A+D);
        }else{
            printf("%d",A+C);
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&A,&B,&C,&D);
     ^
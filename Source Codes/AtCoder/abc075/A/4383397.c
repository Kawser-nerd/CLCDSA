#include <stdio.h>

int main(){
    int A,B,C;
    scanf("%d%d%d", &A,&B,&C);
    if (A == B) {
        printf("%d",C);
    }else if(B == C){
        printf("%d", A);
    }else{
        printf("%d", B);
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &A,&B,&C);
     ^
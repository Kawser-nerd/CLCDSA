#include<stdio.h>

int main(){
    int A,B,C;
    scanf("%d",&A);
    scanf("%d",&B);
    scanf("%d",&C);

    if(C<=A+B+1){
        printf("%d",B+C);
    }

    else{
        printf("%d",A+2*B+1);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&B);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&C);
     ^
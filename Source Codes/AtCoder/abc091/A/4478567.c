#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,D;
    char S[3];
    scanf("%d %d %d",&A,&B,&C);
    if(A+B<C){
        printf("No");
    }else{
        printf("Yes");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^
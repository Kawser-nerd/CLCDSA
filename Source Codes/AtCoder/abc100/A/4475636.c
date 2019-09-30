#include<stdio.h>
#include<string.h>
int main(void){
    int A,B,C,cou;
    char S[100000];
    scanf("%d %d",&A,&B);
    if((A<=8)&&(B<=8)){
        printf("Yay!");
    }else{
        printf(":(");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&A,&B);
     ^
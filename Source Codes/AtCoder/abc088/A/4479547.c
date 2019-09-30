#include<stdio.h>
#include<string.h>
int main(void){
    int A,B;
    scanf("%d %d",&A,&B);
    if(A%500<=B){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&A,&B);
     ^
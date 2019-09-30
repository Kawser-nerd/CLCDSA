#include <stdio.h>
int main(void){
    // Your code here!
    int A,B;
    scanf("%d %d",&A,&B);
    if(A*B%2==0){
        printf("No");
    }else{
        printf("Yes");
    }
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&A,&B);
     ^
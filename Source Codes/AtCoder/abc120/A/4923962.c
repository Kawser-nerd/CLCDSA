#include <stdio.h>
int main(void){
    int A,B,C,R;
    
    scanf("%d %d %d",&A,&B,&C);
    
    R=B/A;
    
    if(R<C){
        printf("%d",R);
    }
    else{
        printf("%d",C);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&A,&B,&C);
     ^
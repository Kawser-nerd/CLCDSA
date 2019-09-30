#include <stdio.h>
int main(void){
    int A,B;
    scanf("%d %d",&A,&B);
    if(A<0 && B>0){
        printf("%d\n",B-A-1);
        }
        else{
            printf("%d\n",B-A);
        }
        
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&A,&B);
     ^
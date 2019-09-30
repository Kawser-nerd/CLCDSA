#include<stdio.h>
int main(void){
    int A,B,C,D;
    scanf("%d %d %d %d",&A,&B,&C,&D);
    int sum = 0;
    if(A<B) sum += A;
    else sum += B;
    if(C<D) sum += C;
    else sum += D;
    printf("%d\n",sum);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d %d",&A,&B,&C,&D);
     ^
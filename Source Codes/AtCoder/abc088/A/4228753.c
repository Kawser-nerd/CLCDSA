#include<stdio.h>
int main(void){
    int N,A;
    scanf("%d",&N);
    scanf("%d",&A);
    if((N%500) <= A) printf("Yes\n");
    else printf("No\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
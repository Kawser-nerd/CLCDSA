#include<stdio.h>
    #include<string.h>
    int main(void){
    int A,B;
    scanf("%d",&A);
    scanf("%d",&B);
    printf("%d\n",A-B);

    return 0;
    } ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&B);
     ^
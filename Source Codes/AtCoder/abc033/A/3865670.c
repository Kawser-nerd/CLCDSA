#include<stdio.h>
int main(void)
{
    int N;
    scanf("%d \n",&N);
    if(N%1111==0){
        printf("SAME\n");
        return 0;
    }
    printf("DIFFERENT\n");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d \n",&N);
     ^
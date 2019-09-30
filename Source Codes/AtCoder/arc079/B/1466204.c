#include <stdio.h>
int main(void){
    long long int K;
    scanf("%lld",&K);
    long long int a[50]={};
    for(int i=0;i<50;i++)a[i]=((long long int)(K/50))+49-K%50;
    for(int i=0;i<(K%50);i++)a[i]+=50;
    printf("50\n");
    for(int i=0;i<50;i++)printf("%lld ",a[i]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&K);
     ^
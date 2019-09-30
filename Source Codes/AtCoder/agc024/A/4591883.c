#include<stdio.h>

int main(){
    long long int A,B,C,K;
    scanf("%lld",&A);
    scanf("%lld",&B);
    scanf("%lld",&C);
    scanf("%lld",&K);

    if(K%2==0){
        printf("%lld",A-B);
    }

    if(K%2 == 1){
        printf("%lld",B-A);
    }

return 0;

} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&A);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&B);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&C);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&K);
     ^
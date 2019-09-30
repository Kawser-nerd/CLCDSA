#include <stdio.h>

long long int kaijou(int k){
    if(k==0)return 1;
    else return (k*kaijou(k-1))%1000000007;
}

int main(void){
    int N,M;
    long long int kotae=1;
    scanf("%d %d",&N,&M);
    if(N<M){
        int kari;
        kari=M;
        M=N;
        N=kari;
    }
    if(N-M>1)printf("0");
    else{
        if(N-M==1)kotae=kaijou(N)*kaijou(M);
        if(N-M==0)kotae=2*kaijou(N)*kaijou(N);
        kotae%=1000000007;
        printf("%lld",kotae);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&M);
     ^
#include <stdio.h>
#define SUSHU 1
#define HESHU 2
#define DOUBUSHI 3//???……

long long judge(long long n){
    if (n<=1) return DOUBUSHI;
    for (long long i = 2; i*i <= n; ++i) {
        if(n%i==0){
            return HESHU;
        }
    }
    return SUSHU;
}

int main(){
    long long n,k=0,ttem,flag;
    scanf("%lld",&n);
    ttem=n;
    while(ttem>0){
        k+=ttem%10;
        ttem=ttem/10;
    }
    flag=judge(n);
    if (((flag==HESHU) && n%2!=0 && n%5!=0 && k%3!=0)||(flag==SUSHU)){
        printf("Prime\n");
    }
    else{
        printf("Not Prime\n");
    }

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
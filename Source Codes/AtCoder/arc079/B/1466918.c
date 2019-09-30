//simple
#include<stdio.h>

int main(void){
    long long k,a,b,r[64]={0},i,t;
    scanf("%lld",&k);
    printf("50\n");
    a=k/50;
    b=k%50;
    t=49+a-b;
    for(i=1;i<=50;i++){
        if(i<=b){r[i]=t+51;}
        else{r[i]=t;}
    }
    for(i=1;i<=50;i++){
        if(i==50){printf("%lld\n",r[i]);}else{printf("%lld ",r[i]);}
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&k);
     ^
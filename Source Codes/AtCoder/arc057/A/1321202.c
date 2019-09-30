#include <stdio.h>
int main(void){
    long long int a,k,t=0;
    scanf("%lld%lld",&a,&k);
    if(k==0){
        t=2000000000000-a;
    }
    if(k!=0){
    while(a<2000000000000){
        a+=1+k*a;
        t++;
    }}
    printf("%lld\n",t);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld%lld",&a,&k);
     ^
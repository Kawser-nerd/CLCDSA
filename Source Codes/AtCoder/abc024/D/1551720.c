#include <stdio.h>
#define P 1000000007

long long int nisizaki(long long int n,int po){
    if(po==0)return 1;
    if(po%2==1)return (n*nisizaki(n,po-1))%P;
    return (nisizaki(n,po/2)*nisizaki(n,po/2))%P;
}
long long int gyaku(long long int n){return nisizaki(n,P-2);}

int main(void){
    long long int A,B,C;
    scanf("%lld %lld %lld",&A,&B,&C);
    long long int buri=(A*gyaku(B))%P;
    buri+=A*gyaku(C);
    buri+=P-1;
    buri%=P;
    buri=gyaku(buri);
    long long int R=(((buri*A)%P)*gyaku(C)+P-1)%P;
    long long int c=(buri+P-R-1)%P;
    printf("%lld %lld\n",R,c);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld %lld %lld",&A,&B,&C);
     ^
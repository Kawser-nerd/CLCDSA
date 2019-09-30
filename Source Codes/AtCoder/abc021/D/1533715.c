#include <stdio.h>

long long int gyaku(int k,int po){
    if(po==0)return 1;
    if(po%2)return (gyaku(k,po-1)*k)%1000000007;
    return (gyaku(k,po/2)*gyaku(k,po/2))%1000000007;
}

int main(void){
    int n,k;
    scanf("%d %d",&n,&k);
    long long int ans=1;
    for(int i=1;i<=n+k-1;i++){ans*=i;ans%=1000000007;}
    for(int i=1;i<=n-1;i++){ans*=gyaku(i,1000000005);ans%=1000000007;}
    for(int i=1;i<=k;i++){ans*=gyaku(i,1000000005);ans%=1000000007;}
    printf("%lld\n",ans);
    return 0;
    //ans=(n+k-1)C(k)
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&n,&k);
     ^
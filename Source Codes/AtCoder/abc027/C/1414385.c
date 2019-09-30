#include <stdio.h>
int main(void){
    long long int n,depth=0,ans=1,N,i;
    scanf("%lld",&n);
    for(N=n;N>0;N/=2)depth++;
    if(depth%2==0){
        for(i=0;i<depth-1;i++){
            ans*=2;
            if(i%2==1)ans++;
        }
    if(ans<=n)printf("Takahashi\n");
    else printf("Aoki\n");
}
    else{
        for(i=0;i<depth-1;i++){
            ans*=2;
            if(i%2==0)ans++;
        }
        if(ans<=n)printf("Aoki\n");
        else printf("Takahashi\n");
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
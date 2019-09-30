#include <stdio.h>

int main()
{   long long i,n,j,a[30001],hoge,ans=0;
    scanf("%lld",&n);
        for(i=0;i<n;i++){
       scanf("%lld",&a[i]);
       ans+=(a[i]-1);
    }
    printf("%lld",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:8:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%lld",&a[i]);
        ^
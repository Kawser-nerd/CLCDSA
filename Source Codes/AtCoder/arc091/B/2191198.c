#include <stdio.h>
int main(void)
{
    long int n,k;
    scanf("%ld %ld",&n,&k);
    long long int ans=0;
    if(k==0)
    {
        ans=n*n;
        printf("%lld",ans);
        return 0;
    }
    if(k>=n)
    {
        printf("0");
        return 0;
    }
    ans+=(n-k)*(n-k+1)/2;
    for(int p=k+1;p<n;p++)
    {
        ans+=(p-k)*(n/p-1);
        if(n%p>k-1)ans+=n%p-k+1;
    }
    printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&n,&k);
     ^